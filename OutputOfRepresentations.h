#pragma once
#include <iostream>
#include "Graph.h"

void OutputOfAdjacencyMatrix(std::ostream &ostream, Graph &graph);

void OutputOfIncidenceMatrix(std::ostream &ostream, Graph &graph);

void OutputOfAdjacencyList(std::ostream &ostream, Graph &graph);

void OutputOfListOfEdges(std::ostream &ostream, Graph &graph);

void MenuForOutputs(std::ostream &ostream, Graph &graph);
