cmake_minimum_required(VERSION 2.8.9)
set (CMAKE_CXX_STANDARD 11)
project (genVoltage)
add_executable(genVoltage Adafruit_ADS1015.cpp genVoltage.cpp)
find_package (Threads)

# Link against libraries
target_link_libraries(genVoltage wiringPi pthread ${CMAKE_THREAD_LIBS_INIT})
