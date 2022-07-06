#include "FillingInTheGraphData.h"

//Заполнение данных ориентированного графа по его FO-представлению.
void FillingOrientedByFO(OrientedGraph &graph) {
    size_t index = 0;
    graph.quantity_of_edges = graph.FO.size() - 1 - graph.quantity_of_vertexes;
    graph.incidence_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_edges, 0));
    graph.adjacency_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_vertexes, 0));
    for (size_t i = 2; i < graph.FO.size(); ++i) {
        if (graph.FO[i] == 0) {
            index++;
        } else {
            graph.adjacency_matrix[index][graph.FO[i] - 1] = 1;
            graph.adjacency_list[index + 1].insert(graph.FO[i]);
            graph.list_of_edges.push_back(std::make_pair(index + 1, graph.FO[i]));
            graph.incidence_matrix[index][i - 2 - index] = 1;
            graph.incidence_matrix[graph.FO[i] - 1][i - 2 - index] = -1;
        }
    }
}

//Заполнение данных ориентированного графа по его FI-представлению.
void FillingOrientedByFI(OrientedGraph &graph) {
    size_t index = 0;
    graph.quantity_of_edges = graph.FI.size() - 1 - graph.quantity_of_vertexes;
    graph.incidence_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_edges, 0));
    graph.adjacency_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_vertexes, 0));
    for (size_t i = 2; i < graph.FI.size(); ++i) {
        if (graph.FI[i] == 0) {
            index++;
        } else {
            graph.adjacency_matrix[graph.FI[i] - 1][index] = 1;
            graph.adjacency_list[graph.FI[i]].insert(index + 1);
            graph.list_of_edges.push_back(std::make_pair(graph.FI[i], index + 1));
            graph.incidence_matrix[index][i - 2 - index] = -1;
            graph.incidence_matrix[graph.FI[i] - 1][i - 2 - index] = 1;
        }
    }
}

//Заполнение данных ориентированного графа по его MFO-представлению.
void FillingOrientedByMFO(OrientedGraph &graph) {
    graph.quantity_of_edges = graph.MFO_E.size();
    graph.incidence_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_edges, 0));
    graph.adjacency_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_vertexes, 0));
    int index_of_vertex = 0;
    for (int i = 0; i < graph.MFO_E.size(); ++i) {
        graph.adjacency_matrix[index_of_vertex][graph.MFO_E[i] - 1] = 1;
        graph.adjacency_list[index_of_vertex + 1].insert(graph.MFO_E[i]);
        graph.list_of_edges.push_back(std::make_pair(index_of_vertex + 1, graph.MFO_E[i]));
        graph.incidence_matrix[index_of_vertex][i] = 1;
        graph.incidence_matrix[graph.MFO_E[i] - 1][i] = -1;
        if (i == graph.MFO_V[index_of_vertex]) {

            index_of_vertex++;
        }
    }
}

//Заполнение данных ориентированного графа по его MFI-представлению.
void FillingOrientedByMFI(OrientedGraph &graph) {
    graph.quantity_of_edges = graph.MFI_E.size();
    graph.incidence_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_edges, 0));
    graph.adjacency_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_vertexes, 0));
    int index_of_vertex = 0;
    for (int i = 0; i < graph.MFI_E.size(); ++i) {
        graph.adjacency_matrix[graph.MFI_E[i] - 1][index_of_vertex] = 1;
        graph.adjacency_list[graph.MFI_E[i]].insert(index_of_vertex + 1);
        graph.list_of_edges.push_back(std::make_pair(graph.MFI_E[i], index_of_vertex + 1));
        graph.incidence_matrix[index_of_vertex][i] = -1;
        graph.incidence_matrix[graph.MFI_E[i] - 1][i] = 1;
        if (i == graph.MFI_V[index_of_vertex]) {
            index_of_vertex++;
        }
    }
}

//Заполнение данных неориентированного графа по его FO-представлению.
void FillingUnorientedByFO(UnorientedGraph &graph) {
    size_t index = 0;
    graph.quantity_of_edges = (graph.FO.size() - 1 - graph.quantity_of_vertexes) / 2;
    graph.incidence_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_edges, 0));
    graph.adjacency_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_vertexes, 0));
    for (size_t i = 2; i < graph.FO.size(); ++i) {
        if (graph.FO[i] == 0) {
            index++;
        } else {
            graph.adjacency_matrix[index][graph.FO[i] - 1] = 1;
            graph.adjacency_list[index + 1].insert(graph.FO[i]);
            if (index + 1 < graph.FO[i]) {
                graph.list_of_edges.push_back(std::make_pair(index + 1, graph.FO[i]));
                graph.incidence_matrix[index][graph.list_of_edges.size() - 1] = 1;
                graph.incidence_matrix[graph.FO[i] - 1][graph.list_of_edges.size() - 1] = 1;
            }
        }
    }
}

//Заполнение данных неориентированного графа по его BFO-представлению.
void FillingUnorientedByBFO(UnorientedGraph &graph) {
    size_t index = 0;
    graph.quantity_of_edges = graph.BFO.size() - 1 - graph.quantity_of_vertexes;
    graph.incidence_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_edges, 0));
    graph.adjacency_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_vertexes, 0));
    for (size_t i = 2; i < graph.BFO.size(); ++i) {
        if (graph.BFO[i] == 0) {
            index++;
        } else {
            graph.adjacency_matrix[index][graph.BFO[i] - 1] = 1;
            graph.adjacency_list[index + 1].insert(graph.BFO[i]);
            graph.list_of_edges.push_back(std::make_pair(index + 1, graph.BFO[i]));
            graph.incidence_matrix[index][i - 2 - index] = 1;
            graph.adjacency_matrix[graph.BFO[i] - 1][index] = 1;
            graph.adjacency_list[graph.BFO[i]].insert(index + 1);
            graph.incidence_matrix[graph.BFO[i] - 1][i - 2 - index] = 1;
        }
    }
}

//Заполнение данных неориентированного графа по его BMFO-представлению.
void FillingUnorientedByBMFO(UnorientedGraph &graph) {
    graph.quantity_of_edges = graph.BMFO_E.size();
    graph.incidence_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_edges, 0));
    graph.adjacency_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_vertexes, 0));
    int index_of_vertex = 0;
    for (int i = 0; i < graph.BMFO_E.size(); ++i) {
        graph.adjacency_matrix[index_of_vertex][graph.BMFO_E[i] - 1] = 1;
        graph.adjacency_list[index_of_vertex + 1].insert(graph.BMFO_E[i]);
        graph.list_of_edges.push_back(std::make_pair(index_of_vertex + 1, graph.BMFO_E[i]));
        graph.incidence_matrix[index_of_vertex][i] = 1;
        graph.adjacency_matrix[graph.BMFO_E[i] - 1][index_of_vertex] = 1;
        graph.adjacency_list[graph.BMFO_E[i]].insert(index_of_vertex + 1);
        graph.incidence_matrix[graph.BMFO_E[i] - 1][i] = 1;
        if (i == graph.BMFO_V[index_of_vertex]) {
            index_of_vertex++;
        }
    }
}

//Заполнение данных ориентированного графа по его MFO-представлению.
void FillingUnorientedByMFO(UnorientedGraph &graph) {
    graph.quantity_of_edges = graph.MFO_E.size() / 2;
    graph.incidence_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_edges, 0));
    graph.adjacency_matrix = std::vector<std::vector<int>>
            (graph.quantity_of_vertexes, std::vector<int>(graph.quantity_of_vertexes, 0));
    int index_of_vertex = 0;
    for (int i = 0; i < graph.MFO_E.size(); ++i) {
        graph.adjacency_matrix[index_of_vertex][graph.MFO_E[i] - 1] = 1;
        graph.adjacency_list[index_of_vertex + 1].insert(graph.MFO_E[i]);
        if (index_of_vertex + 1 < graph.MFO_E[i]) {
            graph.list_of_edges.push_back(std::make_pair(index_of_vertex + 1, graph.MFO_E[i]));
            graph.incidence_matrix[index_of_vertex][graph.list_of_edges.size() - 1] = 1;
            graph.incidence_matrix[graph.MFO_E[i] - 1][graph.list_of_edges.size() - 1] = 1;
        }
        if (i == graph.MFO_V[index_of_vertex]) {
            index_of_vertex++;
        }
    }
}