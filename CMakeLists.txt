cmake_minimum_required(VERSION 3.17)
project(new_sorts)

set(CMAKE_CXX_STANDARD 14)

add_executable(new_sorts main.cpp HelpFunctions.h Node.h DynamicArray.h LinkedList.h Sequences.h ArraySequence.h LinkedListSequence.h ISorter.h SimpleTests.h Time.h)