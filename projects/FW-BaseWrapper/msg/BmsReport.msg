# Message containing data from a battery management system

Header header
# Celsius
float64 temperature
# Calculated by summing the voltage of each cell
float64 total_voltage
float64 current

# In DecimalPercent (0% -> 0., 100%->1.)
float64 relative_state_of_charge
float64 remaining_capacity
float64 full_charge_capacity
float64 charging_current
float64 charging_voltage

# In DecimalPercent (0% -> 0., 100%->1.)
float64 relative_state_of_health
float64[] cell_voltages
# Measured by ADC of GND and last cell voltage
float64 total_cell_voltage
# Measured by ADC of output port
float64 pack_voltage

# Status Enumerator
uint16 operation_status
uint16 OPERATION_STATUS_INIT = 0
uint16 OPERATION_STATUS_WAKEUP = 1
uint16 OPERATION_STATUS_DISCHARGING = 2
uint16 OPERATION_STATUS_CHARGING = 3
# 0x0004 reserved
uint16 OPERATION_STATUS_CHARGE_TERMINATE = 5
uint16 OPERATION_STATUS_CHARGE_WAIT = 6
# 0x0007 - 0x000F reserved
uint16 OPERATION_STATUS_CHARGE_OVER_HEAT = 16
uint16 OPERATION_STATUS_DISCHARGE_OVER_HEAT = 17
uint16 OPERATION_STATUS_OVER_CHARGE_CURRENT = 18
uint16 OPERATION_STATUS_OVER_DISCHARGE_CURRENT = 19
uint16 OPERATION_STATUS_SHORT_CURRENT = 20
uint16 OPERATION_STATUS_OVER_VOLTAGE = 21
uint16 OPERATION_STATUS_SECOND_THERMAL_OVER_HEAT = 22
# 0x0017 - 0x001D reserved
uint16 OPERATION_STATUS_POWER_DOWN = 30
# 0x001F reserved
uint16 OPERATION_STATUS_INITIAL_CALIBRATION = 32
# 0x0021 - 0x0098 reserved
uint16 OPERATION_STATUS_FIXED_CONSTANT_DATA_ERROR = 153
# 0x0100 and above reserved
