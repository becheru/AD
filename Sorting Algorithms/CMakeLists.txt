cmake_minimum_required(VERSION 3.3)
project(MergeSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES main.c vectors.h vectors.c merge_sort.c sort.h selection_sort.c insertion_sort.c quick_sort.c basic.c basic.h)
add_executable(MergeSort ${SOURCE_FILES} vectors.h vectors.c merge_sort.c sort.h)