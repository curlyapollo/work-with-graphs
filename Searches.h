#pragma once
#include <iostream>
#include "Graph.h"

void DFSWithRecursion(std::ostream &ostream, Graph &graph, int vertex);

void DFSWithoutRecursion(std::ostream &ostream, Graph &graph);

void BFS(std::ostream &ostream, Graph &graph);

void MenuForSearches(std::ostream &ostream, Graph &graph);

