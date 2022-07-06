#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Graph.h"

std::vector<std::string> Split(const std::string &str, char delimiter);

std::pair<int, std::vector<int>> ProcessingFOorFIString(const std::string &f_string);

std::vector<int> InputOfFI(std::istream &istream, OrientedGraph &graph);

std::vector<int> InputOfFO(std::istream &istream, Graph &graph);

std::vector<int> InputOfBFO(std::istream &istream, Graph &graph);

std::vector<int> InputOfVector(const std::string &numbers);

std::pair<std::vector<int>, std::vector<int>> InputOfMFO(std::istream &istream, Graph &graph);

std::pair<std::vector<int>, std::vector<int>> InputOfBMFO(std::istream &istream, Graph &graph);

std::pair<std::vector<int>, std::vector<int>> InputOfMFI(std::istream &istream, OrientedGraph &graph);
