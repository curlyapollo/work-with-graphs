#pragma once
#include <map>
#include <set>
#include <vector>


//Класс графа.
class Graph {
public:
    //Количество вершин.
    int quantity_of_vertexes;

    //Количество рёбер.
    int quantity_of_edges;

    //Мапа для поисков, отмечающая, пройдена ли вершина.
    std::map<int, bool> map_for_search;

    //Матрица смежности.
    std::vector<std::vector<int>> adjacency_matrix;

    //Матрица инцидентности.
    std::vector<std::vector<int>> incidence_matrix;

    //FO-представление графа.
    std::vector<int> FO;

    //Секции MFO-представления графа.
    std::vector<int> MFO_E;

    //Описание секций MFO-представления графа.
    std::vector<int> MFO_V;

    //Список смежности.
    std::map<int, std::set<int>> adjacency_list;

    //Список рёбер.
    std::vector<std::pair<int, int>> list_of_edges;
};

//Класс ориентированного графа.
class OrientedGraph : public Graph {
public:
    //FI-представление графа.
    std::vector<int> FI;

    //Секции MFI-представления графа.
    std::vector<int> MFI_E;

    //Описание секций MFI-представления графа.
    std::vector<int> MFI_V;
};

class UnorientedGraph : public Graph {
public:
    //BFO-представление графа.
    std::vector<int> BFO;

    //Секции BMFO-представления графа.
    std::vector<int> BMFO_E;

    //Описание секций BMFO-представления графа.
    std::vector<int> BMFO_V;
};