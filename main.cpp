#include <iostream>
#include <fstream>
#include "inc/Kuhn.hpp"

int main () {
  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");

  if (!fin.is_open()) {
    std::cout << "Can't open input file" << std::endl;
    return 1;
  }

  Graph graph;
  size_t countEdges;
  fin >> countEdges;
  for (size_t i = 0; i < countEdges; ++i) {
    int from, to;
    fin >> from >> to;
    graph.add_edge(from-1, to-1);
  }

  auto res = graph.find_edges();

  for (auto elem : res)
    fout << elem.first+1 << ':' << elem.second+1 << std::endl;

  return 0;
}
