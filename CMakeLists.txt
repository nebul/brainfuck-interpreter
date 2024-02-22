cmake_minimum_required(VERSION 3.14)

project(BrainfuckInterpreter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BrainfuckInterpreter main.cpp brainfuck_interpreter.cpp)
