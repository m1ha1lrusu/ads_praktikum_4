cmake_minimum_required(VERSION 3.28)
project(4)

set(CMAKE_CXX_STANDARD 26)

add_executable(4 main.cpp
        catch.h
        DijkstraSP.cpp
        DijkstraSP.h
        EdgeWeightedDigraph.cpp
        EdgeWeightedDigraph.h
        EdgeWeightedGraph.cpp
        EdgeWeightedGraph.h
        Graphsearch.h
        GraphTest.cpp
        KruskalMST.cpp
        KruskalMST.h
        PrimMST.cpp
        PrimMST.h
        PriorityQueue.h
)
