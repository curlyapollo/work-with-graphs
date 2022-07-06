#include <queue>
#include <stack>
#include "Searches.h"

//Рекурсивный DFS-поиск.
void DFSWithRecursion(std::ostream &ostream, Graph &graph, int vertex) {
    graph.map_for_search[vertex] = true;
    ostream << vertex << " ";
    for (auto el : graph.adjacency_list[vertex]) {
        if (!graph.map_for_search[el]) {
            DFSWithRecursion(ostream, graph, el);
        }
    }
}

//Нерекурсивный DFS-поиск.
void DFSWithoutRecursion(std::ostream &ostream, Graph &graph) {
    std::stack<int> stack;
    for (int vertex = 1; vertex < graph.quantity_of_vertexes + 1; ++vertex) {
        if (!graph.map_for_search[vertex]) {
            graph.map_for_search[vertex] = true;
            stack.push(vertex);
            while (!stack.empty()) {
                vertex = stack.top();
                ostream << vertex << " ";
                stack.pop();
                for (auto element : graph.adjacency_list[vertex]) {
                    if (!graph.map_for_search[element]) {
                        graph.map_for_search[element] = true;
                        stack.push(element);
                    }
                }
            }
        }
    }
    graph.map_for_search.clear();
}

//BFS-поиск.
void BFS(std::ostream &ostream, Graph &graph) {
    std::queue<int> queue;
    for (int vertex = 1; vertex < graph.quantity_of_vertexes + 1; ++vertex) {
        if (!graph.map_for_search[vertex]) {
            graph.map_for_search[vertex] = true;
            queue.push(vertex);
            while (!queue.empty()) {
                vertex = queue.front();
                ostream << vertex << " ";
                queue.pop();
                for (auto element : graph.adjacency_list[vertex]) {
                    if (!graph.map_for_search[element]) {
                        graph.map_for_search[element] = true;
                        queue.push(element);
                    }
                }
            }
        }
    }
    graph.map_for_search.clear();
}

//Меню для работы с поиском.
void MenuForSearches(std::ostream &ostream, Graph &graph) {
    std::cout << "Choose which search you want to use(1/2):\n"
                 "1. DFS.\n2. BFS.\n";
    int choice_about_search;
    std::cin >> choice_about_search;
    if (choice_about_search == 1) {
        std::cout << "Choose which search you want to use(1/2):\n"
                     "1. with recursion.\n2. without recursion.\n";
        int choice_about_recursion;
        std::cin >> choice_about_recursion;
        if (choice_about_recursion) {
            ostream << "DFS with recursion:\n";
            for (int i = 1; i < graph.quantity_of_vertexes + 1; ++i) {
                if (!graph.map_for_search[i]) {
                    DFSWithRecursion(ostream, graph, i);
                }
            }
            ostream << '\n';
            graph.map_for_search.clear();
        } else {
            ostream << "DFS without recursion:\n";
            DFSWithoutRecursion(ostream, graph);
            ostream << '\n';
        }
    } else {
        ostream << "BFS:\n";
        BFS(ostream, graph);
        ostream << '\n';
    }
}