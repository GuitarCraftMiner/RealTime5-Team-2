cmake_minimum_required(VERSION 2.8.9)
set (CMAKE_CXX_STANDARD 11)
project (main)
add_executable(main Adafruit_ADS1015.cpp genVoltage.cpp DemoThread.cpp pwmSet.cpp main.cpp)
find_package (Threads)

# Link against libraries
target_link_libraries(main wiringPi pthread ${CMAKE_THREAD_LIBS_INIT})
