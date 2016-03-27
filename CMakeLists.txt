cmake_minimum_required(VERSION 3.4)
project(datastruct)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp list.cpp queue.cpp stack.cpp btree.cpp quick_sort.cpp)
add_executable(datastruct ${SOURCE_FILES})