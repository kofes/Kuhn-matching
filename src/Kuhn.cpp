#include "../inc/Kuhn.hpp"

#include <iostream>

Graph::Graph( int count ) {
  _graph.resize(count);
};

void Graph::clear() {
  _graph.clear();
};

void Graph::add_edge(int from, int to) {
  if (_graph.size() <= from || _graph.size() <= to)
    _graph.resize(std::max(from+1, to+1));

  _graph[from].insert(to);
  _graph[to].insert(from);
};

std::list< std::pair<int, int> > Graph::find_edges() {
  std::vector<bool> visited(_graph.size(), false);
  std::vector<int> match(_graph.size(), -1);
  for (int i = 0; i < _graph.size(); ++i) {
    std::fill(visited.begin(), visited.end(), false);
    dfs(i, visited, match);
  }

  std::list< std::pair<int, int> > res;
  for (int i = 0; i < _graph.size(); ++i)
    if (match[i] != -1)
      res.push_back(std::make_pair(i, match[i]));
  return res;
};

bool Graph::dfs(int from, std::vector<bool>& visited, std::vector<int>& match) {
  if (visited[from])
    return false;
  visited[from] = true;
  for (int v : _graph[from]) {
    if (match[v] == -1 || dfs(match[v], visited, match)) {
      match[v] = from;
      return true;
    }
  }
  return false;
};
