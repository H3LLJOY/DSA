cmake_minimum_required(VERSION 3.27)
project(Single_Source_Shortest_Path)

set(CMAKE_CXX_STANDARD 17)

add_executable(Single_Source_Shortest_Path Dijkstra.cpp
        "Bellman Ford.cpp"
        Inclass.cpp)
