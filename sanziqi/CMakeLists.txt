cmake_minimum_required(VERSION 3.25)
project(sanziqi C)

set(CMAKE_C_STANDARD 11)

add_executable(sanziqi test.c game.c game.h)
