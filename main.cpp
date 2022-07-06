#include <fstream>
#include <iostream>
#include <tuple>
#include "InputOfRepresentations.h"
#include "FillingInTheGraphData.h"
#include "OutputOfRepresentations.h"
#include "Searches.h"

//Выяснение у пользователя, с каким типом графа он хочет работать.
bool IsWorkingWithOriented() {
    std::cout << "Now tell me which graph we will work with(1/2):\n"
                 "1. Oriented.\n2. Unoriented.\n";
    int choice_of_graph;
    std::cin >> choice_of_graph;
    return choice_of_graph == 1;
}

//Меню работы с ориентированным графом.
OrientedGraph MenuForOriented(std::istream &istream) {
    OrientedGraph graph;
    std::cout << "What view are we working in?(1-4)\n"
                 "1. FO\n2. FI\n3. MFO\n4. MFI\n";
    int choice_of_representation;
    std::cin >> choice_of_representation;
    if (choice_of_representation == 1) {
        graph.FO = InputOfFO(istream, graph);
        FillingOrientedByFO(graph);
    } else if (choice_of_representation == 2) {
        graph.FI = InputOfFI(istream, graph);
        FillingOrientedByFI(graph);
    } else if (choice_of_representation == 3) {
        auto result = InputOfMFO(istream, graph);
        graph.MFO_E = result.first;
        graph.MFO_V = result.second;
        FillingOrientedByMFO(graph);
    } else {
        auto result = InputOfMFI(istream, graph);
        graph.MFI_E = result.first;
        graph.MFI_V = result.second;
        FillingOrientedByMFI(graph);
    }
    return graph;
}

//Меню работы с неориентированным графом.
UnorientedGraph MenuForUnoriented(std::istream &istream) {
    UnorientedGraph graph;
    std::cout << "What view are we working in?(1-4)\n"
                 "1. FO\n2. MFO\n3. BFO\n4. BMFO\n";
    int choice_of_representation;
    std::cin >> choice_of_representation;
    if (choice_of_representation == 1) {
        graph.FO = InputOfFO(istream, graph);
        FillingUnorientedByFO(graph);
    } else if (choice_of_representation == 2) {
        auto result = InputOfMFO(istream, graph);
        graph.MFO_E = result.first;
        graph.MFO_V = result.second;
        FillingUnorientedByMFO(graph);
    } else if (choice_of_representation == 3) {
        graph.BFO = InputOfBFO(istream, graph);
        FillingUnorientedByBFO(graph);
    } else {
        auto result = InputOfBMFO(istream, graph);
        graph.BMFO_E = result.first;
        graph.BMFO_V = result.second;
        FillingUnorientedByBMFO(graph);
    }
    return graph;
}

//Ввод графа из потока.
Graph InputFromStream(std::istream &istream) {
    bool is_oriented = IsWorkingWithOriented();
    Graph graph;
    if (is_oriented) {
        graph = MenuForOriented(istream);
    } else {
        graph = MenuForUnoriented(istream);
    }
    return graph;
}

//Главное меню работы с графом.
void MainMenu(Graph &graph, std::ostream &ostream) {
    std::cout << "Choose what you want to do with the entered graph(1-4):\n"
                 "1. Output of degrees of vertexes.\n2. Output of the number of edges.\n"
                 "3. Output of the graph in a certain representation.\n4. Vertex traversal.\n";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            for (int i = 0; i < graph.quantity_of_vertexes; ++i) {
                ostream << i + 1 << " vertex: " << graph.adjacency_list[i + 1].size() << '\n';
            }
            break;
        case 2:
            ostream << "The number of edges of this graph - " << graph.quantity_of_edges << '\n';
            break;
        case 3:
            MenuForOutputs(ostream, graph);
            break;
        default:
            MenuForSearches(ostream, graph);
            break;
    }
}

//Точка входа.
int main() {
    std::ifstream fin;
    std::ofstream fout;
    fin.open("../input.txt", std::ifstream::in);
    fout.open("../output.txt", std::ofstream::out | std::ofstream::trunc);
    std::string is_end_of_program;
    std::string is_end_of_graph;
    Graph graph;
    do {
        std::cout << "Hello, please select an input method(1/2):\n"
                     "1. Console input.\n2. File input.\n";
        int choice_of_communication;
        std::cin >> choice_of_communication;
        if (choice_of_communication == 1) {
            graph = InputFromStream(std::cin);
        } else {
            graph = InputFromStream(fin);
        }
        do {
            std::cout << "Choose a output method(1/2):\n"
                         "1. Console output.\n2. File output.\n";
            std::cin >> choice_of_communication;
            if (choice_of_communication == 1) {
                MainMenu(graph, std::cout);
            } else {
                MainMenu(graph, fout);
            }
            std::cout << "Do you still want to work with this graph? Enter 'no',"
                         " if you do not want, enter any character (according to README).\n";
            std::cin >> is_end_of_graph;
        } while (is_end_of_graph != "no");
        std::cout
        << "Enter 'end' to end the program. If you want to continue, enter any character"
           " (according to the README).\n";
        std::cin >> is_end_of_program;
    } while (is_end_of_program != "end");

}