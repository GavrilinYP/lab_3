cmake_minimum_required(VERSION 3.6)
project(2_Raz)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS -static)
set(SOURCE_FILES main.cpp Temperature.cc)
add_executable(2_Raz ${SOURCE_FILES})
enable_testing()
add_test(NAME test_input COMMAND test_input)
