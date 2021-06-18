/**
 * @file Graph.cpp
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief Graph
 * @version 0.1
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Graph.h"

#include <cmath>
#include <string>

using namespace std;

namespace Euler {
void Graph::init_graph() {
  vector<string> file_content = get_file_content();
  int graph_size = sqrt(file_content.size());
  // resize
  _graph.resize(graph_size);
  for (int row = 0; row < graph_size; ++row) {
    _graph[row].resize(graph_size);
  }
  // add graph
  for (int i = 0; i < graph_size; ++i) {
    for (int j = 0; j < graph_size; ++j) {
      _graph[i][j] = stoi(file_content[i * graph_size + j]);
    }
  }
}
}  // namespace Euler