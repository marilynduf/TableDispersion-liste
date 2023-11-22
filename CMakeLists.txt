cmake_minimum_required(VERSION 3.26)
project(code_hashtable)

set(CMAKE_CXX_STANDARD 11)

add_executable(code_hashtable main.cpp
        hash.cpp)
