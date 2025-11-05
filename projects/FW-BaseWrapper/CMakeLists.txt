cmake_minimum_required(VERSION 3.0.2)
project(example_node)

find_package(catkin REQUIRED COMPONENTS roscpp message_generation std_msgs)

add_message_files(DIRECTORY msg)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS roscpp message_runtime std_msgs std_srvs INCLUDE_DIRS include)

include_directories(include ${catkin_INCLUDE_DIRS})

install(DIRECTORY include/ DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})

add_library(${PROJECT_NAME}_lib SHARED
    src/base.cpp
    src/bms.cpp
    src/motor.cpp
)
# Ensure generated message headers are built before compiling the library
add_dependencies(${PROJECT_NAME}_lib ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
install(TARGETS ${PROJECT_NAME}_lib DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib ${catkin_LIBRARIES})
# Ensure generated message headers are built before compiling the node
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
install(TARGETS ${PROJECT_NAME} DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
