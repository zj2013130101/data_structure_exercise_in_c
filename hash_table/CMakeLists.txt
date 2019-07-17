cmake_minimum_required(VERSION 3.13)
project(data_structure_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(hash_table main.c hashTbl_list.c hashTbl_detect.c hashTbl_detect.h rehash.c rehash.h hash_function.c)
