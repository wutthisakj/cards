cmake_minimum_required(VERSION 3.5)

project(Cards LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cards main.cpp apstring.cpp)
