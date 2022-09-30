cmake_minimum_required(VERSION 3.20)
project(subs C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(subs
        main.c retrosub.c retrosub.h matrix/Matrix.c matrix/Matrix.h primitive-matrix/matrix.c primitive-matrix/matrix.h)
