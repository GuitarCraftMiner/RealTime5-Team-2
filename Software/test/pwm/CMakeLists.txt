cmake_minimum_required(VERSION 2.8.9)
set (CMAKE_CXX_STANDARD 11)
project (pwmSet)
add_executable(pwmSet pwmSet.cpp)

# Link against libraries
target_link_libraries(pwmSet wiringPi ${CMAKE_THREAD_LIBS_INIT})
