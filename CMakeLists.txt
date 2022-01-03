cmake_minimum_required(VERSION 3.5)

project(SP_PC LANGUAGES C)
set(CMAKE_C_FLAGS "-Wall")

add_executable(SP_PC
    src/main.c
    src/parameters.c
    src/ford_fulkerson.c
    src/loader.c
    src/vector.c
    src/node.c
    src/edge.c
)
