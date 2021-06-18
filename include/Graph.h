/**
 * @file Graph.h
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief Graph
 * @version 0.1
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <string>
#include <vector>

#include "ReadFile.h"

using namespace std;
#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_
namespace Euler {
class Graph : public ReadFileBase {
 public:
  Graph() = default;
  Graph(const Graph& other) : _graph(other._graph) {}
  Graph(const Graph&& other) : _graph(other._graph) {}
  ~Graph() = default;

  void init_graph();

  int get_size() const { return _graph.size(); }

  void add_edge(int x, int y) { _graph[x][y] = 1; }
  vector<vector<int>> get_graph() const { return _graph; }

 private:
  vector<vector<int>> _graph;
};
}  // namespace Euler
#endif