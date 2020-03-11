cmake_minimum_required(VERSION 2.8.9)
set (CMAKE_CXX_STANDARD 11)
project (adc)
add_executable(adc Adafruit_ADS1015.cpp adc.cpp)

# Link against libraries
target_link_libraries(adc wiringPi)
