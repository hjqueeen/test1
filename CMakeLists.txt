cmake_minimum_required(VERSION 3.26)
project(testvorbereiten C)

set(CMAKE_C_STANDARD 11)

add_executable(testvorbereiten main.c
        myfunction.h
        myfunction.c
        myStack.h
        myStack.c
        myPointerList.h
        myPointerList.c
        mybinarytree.h
        mybinarytree.c
        "sort.h"
        "sort.c"
        binarytreecontact.h
        binarytreecontact.c
        stack.h
        stack.c)
