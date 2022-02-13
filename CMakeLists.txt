cmake_minimum_required(VERSION 3.20)
project(laba5d C)

set(CMAKE_C_STANDARD 11)

add_executable(laba5d main.c)

add_subdirectory(libs)

target_link_libraries(laba5d libs)