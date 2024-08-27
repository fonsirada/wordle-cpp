cmake_minimum_required(VERSION 3.17)
project(wordle)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    wordle
    main.cpp
    wordle.cpp
)

target_link_libraries(wordle ncurses)