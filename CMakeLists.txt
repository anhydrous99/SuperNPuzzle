cmake_minimum_required(VERSION 3.15)
project(SupernPuzzle)

set(CMAKE_CXX_STANDARD 14)

add_executable(SupernPuzzle main.cpp SuperNPuzzle.cpp SuperNPuzzle.h super_queue.h extern/memory_usage.h)