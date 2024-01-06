cmake_minimum_required(VERSION 3.26)
project(testvorbereiten C)

set(CMAKE_C_STANDARD 11)

add_executable(testvorbereiten main.c
        myfunction.h
        myfunction.c
        myStack.h
        myStack.c
        myPointerList.h
        myPointerList.c)
