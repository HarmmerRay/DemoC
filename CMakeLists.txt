cmake_minimum_required(VERSION 3.26)
project(DemoC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DemoC
        kernel/pipe_read_all.c)
