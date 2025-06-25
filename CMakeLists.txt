cmake_minimum_required(VERSION 3.10)
project(ATMSimulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(atm_sim
    main.cpp
    Account.cpp
    utils.cpp
)
