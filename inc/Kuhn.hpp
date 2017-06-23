#pragma once

#include <vector>
#include <set>
#include <list>

#pragma pack(push, 1)
class Graph {
public:
  Graph() {};
  Graph( int count );
  void clear();
  void add_edge(int from, int to);
  //Khun algorithm
  std::list< std::pair<int, int> > find_edges();
private:
  bool dfs(int from, std::vector<bool>& visited, std::vector<int>& matched);
  std::vector< std::set<int> > _graph;
};
#pragma pack(pop)
