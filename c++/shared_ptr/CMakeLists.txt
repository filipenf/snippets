
cmake_minimum_required(VERSION 2.8)

project (shared_ptr_functors)

file(GLOB SOURCE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")

add_executable(
    shared_ptr_functors
	${SOURCE}
)

target_link_libraries(
    shared_ptr_functors
    gtest
    gtest_main
    )
