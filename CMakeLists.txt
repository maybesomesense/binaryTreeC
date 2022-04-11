cmake_minimum_required(VERSION 3.20)
project(treeExample C)

set(CMAKE_C_STANDARD 11)

add_executable(treeExample petclub.c tree.h tree.c)
