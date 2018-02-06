cmake_minimum_required(VERSION 3.9)
project(scoreSort C)

set(CMAKE_C_STANDARD 99)

add_executable(scoreSort main.c mysort.c mysort.h)