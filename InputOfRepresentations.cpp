#include "InputOfRepresentations.h"

//Функция сплита строки по какому-то разделителю.
std::vector<std::string> Split(const std::string &str, char delimiter) {
    std::string_view sv = str;
    std::vector<std::string> vec;
    while (sv.find(delimiter) != std::string::npos) {
        auto n = sv.substr(0, sv.find(delimiter));
        vec.push_back(std::string(n));
        sv = sv.substr(sv.find(delimiter) + 1, sv.size() - sv.find(' ') - 1);
    }
    vec.push_back(std::string(sv));
    return vec;
}

//Преобразование из строки представления в список.
std::pair<int, std::vector<int>> ProcessingFOorFIString(const std::string &f_string) {
    std::pair<int, std::vector<int>> result;
    auto f_vector = Split(f_string, ' ');
    result.first = std::stoi(f_vector.front());
    for (const auto &el : f_vector) {
        result.second.push_back(std::stoi(el));
    }
    return result;
}

//Ввод строки FI-представления графа.
std::vector<int> InputOfFI(std::istream &istream, OrientedGraph &graph) {
    std::cout << "Enter a string for the FI-representation of the graph"
                 " (see the README for instructions):\n";
    std::string fi;
    if (istream.peek() == '\n')
        istream.ignore();
    getline(istream, fi, '\n');
    auto fi_result = ProcessingFOorFIString(fi);
    graph.quantity_of_vertexes = fi_result.first;
    return fi_result.second;
}

//Ввод строки FO-представления графа.
std::vector<int> InputOfFO(std::istream &istream, Graph &graph) {
    std::cout << "Enter a string for the FO-representation of the graph"
                 " (see the README for instructions):\n";
    std::string fo;
    if (istream.peek() == '\n')
        istream.ignore();
    std::getline(istream, fo);
    auto fo_result = ProcessingFOorFIString(fo);
    graph.quantity_of_vertexes = fo_result.first;
    return fo_result.second;
}

//Ввод строки BFO-представления графа.
std::vector<int> InputOfBFO(std::istream &istream, Graph &graph) {
    std::cout << "Enter a string for the BFO-representation of the graph"
                 " (see the README for instructions):\n";
    std::string bfo;
    if (istream.peek() == '\n')
        istream.ignore();
    std::getline(istream, bfo);
    auto bfo_result = ProcessingFOorFIString(bfo);
    graph.quantity_of_vertexes = bfo_result.first;
    return bfo_result.second;
}

//Ввод вектора в виде строки.
std::vector<int> InputOfVector(const std::string &numbers) {
    std::vector<int> result;
    std::istringstream sstream(numbers);
    int number;
    while (sstream >> number) {
        result.push_back(number);
    }
    return result;
}

//Ввод строк MFO-представления графа.
std::pair<std::vector<int>, std::vector<int>>
InputOfMFO(std::istream &istream, Graph &graph) {
    std::cout << "Enter the number of graph vertexes"
                 " (see the README for instructions):\n";
    istream >> graph.quantity_of_vertexes;
    std::cout << "Enter the string ME-representation of the graph"
                 " (see the README for instructions):\n";
    std::string me;
    if (istream.peek() == '\n')
        istream.ignore();
    getline(istream, me);
    std::cout << "Enter the MV-representation string for the graph"
                 " (see the README for instructions):\n";
    std::string mv;
    getline(istream, mv);
    return std::make_pair(InputOfVector(me), InputOfVector(mv));
}

//Ввод строк BMFO-представления графа.
std::pair<std::vector<int>, std::vector<int>>
InputOfBMFO(std::istream &istream, Graph &graph) {
    std::cout << "Enter the number of graph vertexes (see the README for instructions):\n";
    istream >> graph.quantity_of_vertexes;
    std::cout << "Enter a string for the abbreviated ME representation of the graph"
                 " (see the README for instructions):\n";
    std::string me;
    if (istream.peek() == '\n')
        istream.ignore();
    getline(istream, me);
    std::cout << "Enter a string for the abbreviated MV representation of the graph"
                 " (see the README for instructions):\n";
    std::string mv;
    getline(istream, mv);
    return std::make_pair(InputOfVector(me), InputOfVector(mv));
}

//Ввод строк MFI-представления графа.
std::pair<std::vector<int>, std::vector<int>>
InputOfMFI(std::istream &istream, OrientedGraph &graph) {
    std::cout << "Enter the number of graph vertexes (see the README for instructions):\n";
    istream >> graph.quantity_of_vertexes;
    std::cout << "Enter the string for the ME representation of the graph "
                 "(see the README for instructions):\n";
    std::string me;
    if (istream.peek() == '\n')
        istream.ignore();
    getline(istream, me);
    std::cout << "Enter the string for the MV representation of the graph"
                 " (see the README for instructions):\n";
    std::string mv;
    getline(istream, mv);
    return std::make_pair(InputOfVector(me), InputOfVector(mv));
}


