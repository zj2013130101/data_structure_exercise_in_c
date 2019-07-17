cmake_minimum_required(VERSION 3.13)
project(data_structure_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(priority_queue main.c binary_heap.c binary_heap.h left_heap.c left_heap.h binomial_queue.c binomial_queue.h)