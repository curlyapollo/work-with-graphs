cmake_minimum_required(VERSION 3.20)
project(WorkWithGraphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(WorkWithGraphs main.cpp Graph.h InputOfRepresentations.cpp InputOfRepresentations.h FillingInTheGraphData.cpp FillingInTheGraphData.h OutputOfRepresentations.cpp OutputOfRepresentations.h Searches.cpp Searches.h)
