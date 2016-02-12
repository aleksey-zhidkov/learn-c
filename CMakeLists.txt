cmake_minimum_required(VERSION 3.4)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(CMAKE_C_STANDARD 99)

add_executable(char_freq the_c_programming_language/chapter-1/chars_freq.c)
add_executable(dt_ranges the_c_programming_language/chapter-2/dt_ranges.c)
add_executable(binary_search the_c_programming_language/chapter-3/binary_search.c)
