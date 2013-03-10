
cmake_minimum_required(VERSION 2.8)

project (quicksort)

file(GLOB SOURCE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")

add_executable(
    quicksort_sample
	${SOURCE}
)
