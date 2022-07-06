#include "OutputOfRepresentations.h"

//Вывод матрицы смежности.
void OutputOfAdjacencyMatrix(std::ostream &ostream, Graph &graph) {
    ostream << "Adjacency matrix:\nVertexes";
    for (int i = 0; i < graph.quantity_of_vertexes; ++i) {
        ostream << "\t" << i + 1;
    }
    ostream << '\n';
    for (int i = 0; i < graph.quantity_of_vertexes; ++i) {
        ostream << i + 1;
        for (int j = 0; j < graph.quantity_of_vertexes; ++j) {
            ostream << "\t" << graph.adjacency_matrix[i][j];
        }
        ostream << '\n';
    }
}

//Вывод матрицы инцидентности.
void OutputOfIncidenceMatrix(std::ostream &ostream, Graph &graph) {
    ostream << "Incidence matrix:\nVertexes/Edges";
    for (int i = 0; i < graph.quantity_of_edges; ++i) {
        ostream << "\t(" << graph.list_of_edges[i].first <<
                ", " << graph.list_of_edges[i].second << ")";
    }
    ostream << '\n';
    for (int i = 0; i < graph.quantity_of_vertexes; ++i) {
        ostream << i + 1 << '\t';
        for (int j = 0; j < graph.quantity_of_edges; ++j) {
            ostream << "\t" << graph.incidence_matrix[i][j];
        }
        ostream << '\n';
    }
}

//Вывод списка смежности.
void OutputOfAdjacencyList(std::ostream &ostream, Graph &graph) {
    ostream << "Adjacency list:\n";
    for (auto[key, value] : graph.adjacency_list) {
        ostream << key << ":";
        for (auto element : value) {
            ostream << " " << element;
        }
        ostream << '\n';
    }
}

//Вывод списка рёбер.
void OutputOfListOfEdges(std::ostream &ostream, Graph &graph) {
    ostream << "List of edges:\nEdge\tStart\tFinish\n";
    for (int i = 0; i < graph.quantity_of_edges; ++i) {
        ostream << i + 1 << '\t' << graph.list_of_edges[i].first <<
                '\t' << graph.list_of_edges[i].second << '\n';
    }
}

//Меню для вывода представлений графа.
void MenuForOutputs(std::ostream &ostream, Graph &graph) {
    std::cout << "Choose which view to display the graph in:\n"
                 "1. Adjacency matrix.\n2. Incidence matrix.\n"
                 "3. Adjacency list.\n4. List of edges.\n";
    int choice_of_representation;
    std::cin >> choice_of_representation;
    switch (choice_of_representation) {
        case 1:
            OutputOfAdjacencyMatrix(ostream, graph);
            break;
        case 2:
            OutputOfIncidenceMatrix(ostream, graph);
            break;
        case 3:
            OutputOfAdjacencyList(ostream, graph);
            break;
        default:
            OutputOfListOfEdges(ostream, graph);
    }
}



