cmake_minimum_required(VERSION 3.30)
project(projekt1)

set(CMAKE_CXX_STANDARD 20)

add_executable(projekt1 main.cpp
        DynamicArray.h
        LinkedList.h
        LinkedListNode.h
)
