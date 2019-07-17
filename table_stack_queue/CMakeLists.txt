cmake_minimum_required(VERSION 3.13)
project(data_structure_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(table_stack_queue main.c list.c list_cursor.c queue.c stack.c ../hash_table/hashTbl_list.c ../hash_table/hashTbl_list.h)
