cmake_minimum_required(VERSION 3.5)

project(SP_PC LANGUAGES C)
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -ansi -g")

add_executable(flow
    main.c
    parameters.c
    out_file.c
    algorithm.c
    bfs.c
    queue.c
    loader.c
    vector.c
    node.c
    edge.c
)
