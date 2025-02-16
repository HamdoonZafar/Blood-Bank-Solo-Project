cmake_minimum_required(VERSION 3.29)
project(Blood_Bank)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Blood_Bank
    "Blood Bank.cpp"
    "Blood Bank.h"
    main.cpp)
