cmake_minimum_required(VERSION 3.4)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(CMAKE_C_STANDARD 99)

add_library(lib lib/strings.c lib/strings.h)

add_executable(char_freq chapter-1/chars_freq.c)
add_executable(dt_ranges chapter-2/dt_ranges.c)
add_executable(binary_search chapter-3/binary_search.c)
add_executable(strrindex chapter-4/strrindex.c)

target_link_libraries(strrindex lib)
