#!/usr/bin/env python3
"""
Motor control script for testing motor acceleration and deceleration.
This script enables the motor, accelerates to target RPM, waits for specified time,
then decelerates back to 0.0 RPM.
"""

import rospy
from std_srvs.srv import SetBool
from example_node.msg import MotorCommand
import sys
import argparse

# Configuration constants
DEFAULT_MAX_SPEED = 2.0  # Default maximum speed in RPM
MAX_SPEED_LIMIT = 3.0   # Hard limit for maximum speed in RPM
DEFAULT_RAMP_TIME = 5.0  # Default ramp up/down time in seconds
DEFAULT_HOLD_TIME = 3.0  # Default hold time at max speed in seconds


def smooth_change(publisher, current_speed, target_speed, duration=1.0, steps=20):
    """
    Smoothly change motor speed from current to target speed.
    
    Args:
        publisher: ROS publisher for motor commands
        current_speed: Starting speed (RPM)
        target_speed: Target speed (RPM)
        duration: Time in seconds to complete the change
        steps: Number of intermediate steps
    """
    rate = rospy.Rate(steps / duration)
    
    for i in range(steps + 1):
        # Linear interpolation
        speed = current_speed + (target_speed - current_speed) * (i / float(steps))
        
        # Publish command to motors in opposite directions for rotation
        msg = MotorCommand()
        msg.RPM_L = speed
        msg.RPM_R = -speed  # Opposite direction for rotation
        
        publisher.publish(msg)
        rospy.loginfo(f"Motor speed: L={speed:.2f}, R={-speed:.2f} RPM")
        
        if i < steps:
            rate.sleep()
    
    return target_speed


def main():
    """Main function to control motor acceleration and deceleration."""
    # Parse command line arguments
    parser = argparse.ArgumentParser(description='Motor test script with configurable parameters')
    parser.add_argument('--max-speed', type=float, default=DEFAULT_MAX_SPEED,
                        help=f'Maximum speed in RPM (default: {DEFAULT_MAX_SPEED}, max: {MAX_SPEED_LIMIT})')
    parser.add_argument('--ramp-time', type=float, default=DEFAULT_RAMP_TIME,
                        help=f'Time in seconds to ramp up/down (default: {DEFAULT_RAMP_TIME})')
    parser.add_argument('--hold-time', type=float, default=DEFAULT_HOLD_TIME,
                        help=f'Time in seconds to hold at max speed (default: {DEFAULT_HOLD_TIME})')
    
    args = parser.parse_args()
    
    # Validate arguments
    if args.max_speed > MAX_SPEED_LIMIT:
        rospy.logerr(f"Max speed {args.max_speed} exceeds limit of {MAX_SPEED_LIMIT} RPM. Capping to {MAX_SPEED_LIMIT} RPM.")
        args.max_speed = MAX_SPEED_LIMIT
    
    if args.max_speed < 0:
        rospy.logerr("Max speed must be positive")
        return 1
    
    if args.ramp_time <= 0 or args.hold_time < 0:
        rospy.logerr("Ramp time must be positive and hold time must be non-negative")
        return 1
    
    # Initialize ROS node
    rospy.init_node('test_motor', anonymous=True)
    rospy.loginfo("Motor test script started")
    rospy.loginfo(f"Parameters: max_speed={args.max_speed} RPM, ramp_time={args.ramp_time}s, hold_time={args.hold_time}s")
    
    try:
        # Wait for services and topics to be available
        rospy.wait_for_service('/example_node/set_enable_motor', timeout=5.0)
        rospy.loginfo("Motor enable service available")
        
        # Create service proxy for enabling/disabling motor
        enable_motor = rospy.ServiceProxy('/example_node/set_enable_motor', SetBool)
        
        # Create publisher for motor speed commands
        motor_pub = rospy.Publisher('/example_node/motor_speed', MotorCommand, queue_size=10)
        
        # Give publisher time to establish connection
        rospy.sleep(0.5)
        
        # Enable motor
        rospy.loginfo("Enabling motor...")
        response = enable_motor(True)
        if not response.success:
            rospy.logerr("Failed to enable motor")
            return 1
        rospy.loginfo("Motor enabled")
        
        # Start from 0.0 RPM
        current_speed = 0.0
        
        # Calculate number of steps for 100Hz update rate
        steps = int(args.ramp_time * 100)
        
        # Accelerate to max speed
        rospy.loginfo(f"Accelerating to {args.max_speed} RPM over {args.ramp_time} seconds...")
        current_speed = smooth_change(motor_pub, current_speed, args.max_speed, duration=args.ramp_time, steps=steps)
        
        # Wait at constant speed
        if args.hold_time > 0:
            rospy.loginfo(f"Maintaining {args.max_speed} RPM for {args.hold_time} seconds...")
            rospy.sleep(args.hold_time)
        
        # Decelerate to 0.0 RPM
        rospy.loginfo(f"Decelerating to 0.0 RPM over {args.ramp_time} seconds...")
        current_speed = smooth_change(motor_pub, current_speed, 0.0, duration=args.ramp_time, steps=steps)
        
        # Small delay to ensure last command is processed
        rospy.sleep(0.5)
        
        # Disable motor
        rospy.loginfo("Disabling motor...")
        response = enable_motor(False)
        if not response.success:
            rospy.logerr("Failed to disable motor")
            return 1
        rospy.loginfo("Motor disabled")
        
        rospy.loginfo("Motor test completed successfully")
        return 0
        
    except rospy.ROSException as e:
        rospy.logerr(f"ROS error: {e}")
        return 1
    except Exception as e:
        rospy.logerr(f"Unexpected error: {e}")
        return 1
    finally:
        # Ensure motor is stopped and disabled on exit
        try:
            msg = MotorCommand()
            msg.RPM_L = 0.0
            msg.RPM_R = 0.0
            motor_pub.publish(msg)
            rospy.sleep(0.1)
            enable_motor(False)
        except:
            pass


if __name__ == '__main__':
    try:
        sys.exit(main())
    except rospy.ROSInterruptException:
        rospy.loginfo("Motor test interrupted")
        sys.exit(0)

