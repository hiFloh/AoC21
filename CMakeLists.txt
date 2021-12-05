cmake_minimum_required(VERSION 3.19)
project(AoC21)

set(CMAKE_CXX_STANDARD 14)
include_directories(./)
add_executable(AoC21 main.cpp lib.h D1/D1.cpp D2/D2.cpp D2/D2.h D3/D3.cpp D3/D3.h D4/D4.cpp D4/D4.h lib.cpp D5/D5.cpp D5/D5.h)