cmake_minimum_required(VERSION 3.2)
project(athens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    binary_tree.c
    binary_tree.h
    main.c
    minunit.h
    test_binary_tree.c)

add_executable(athens ${SOURCE_FILES})