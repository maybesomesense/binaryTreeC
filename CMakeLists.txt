cmake_minimum_required(VERSION 3.20)
project(treeExample C)

set(CMAKE_C_STANDARD 11)

add_executable(treeExample decanat.c tree.h tree.c)
