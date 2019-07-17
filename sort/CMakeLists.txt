cmake_minimum_required(VERSION 3.13)
project(data_structure_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(sort main.c insert_sort.c insert_sort.h quick_sort.c quick_sort.h heap_sort.c heap_sort.h shell_sort.c shell_sort.h)