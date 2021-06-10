cmake_minimum_required(VERSION 3.16.3)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        lab2
        main.cpp
        myDynamicArray.cpp
        myArraySequence.cpp
        myLinkedList.cpp
        myListSequence.cpp
        myVector.cpp myVector.h myMatrix.cpp myMatrix.h menu.cpp menu.h menuVector.cpp menuVector.h menuMatrix.cpp menuMatrix.h tests.cpp tests.h indexOutOfRange.cpp indexOutOfRange.h)