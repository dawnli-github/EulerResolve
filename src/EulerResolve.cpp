/**
 * @file EulerResolve.cpp
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief Euler Resolve
 * @version 0.1
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/EulerResolve.h"

#include <algorithm>
using namespace std;

namespace Euler {
void EulerCore::init() {
  // resize
  const int _max_size = _graph.size() * (_graph.size() - 1);
  _graph_edge.resize(_max_size);
  _head.resize(_max_size);
  _stack.resize(_max_size);
  _visit.resize(_max_size);
}
void EulerCore::addEdge(int x, int y) {
  ++_tot;
  _graph_edge[_tot].to = y;
  _graph_edge[_tot].next = _head[x];
  _head[x] = _tot;
}
void EulerCore::computeWay() {
  // init stack
  _tot = 1;
  _top = 1;
  _stack[_top] = 1;
  // add edge
  for (int i = 0; i < _graph.size(); ++i) {
    for (int j = 0; j < _graph.size(); ++j) {
      if (_graph[i][j] == 1) {
        addEdge(i, j);
      }
    }
  }
  // simulation of DFS
  int x, i;
  while (_top > 0) {
    x = _stack[_top], i = _head[x];
    while (i && _visit[i]) {
      i = _graph_edge[i].next;
    }
    if (i) {
      ++_top;
      _stack[_top] = _graph_edge[i].to;
      _visit[i] = 1;
      _head[x] = _graph_edge[i].next;
    } else {
      --_top;
      _loop.emplace_back(x);
    }
  }
}

void Resolve::init() {
  const int size = _graph.get_size();
  vector<int> in_num(size);
  vector<int> out_num(size);
  vector<vector<int>> graph = _graph.get_graph();
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      in_num[i] += graph[j][i];
      out_num[i] += graph[i][j];
    }
  }
  int count = 0;
  bool check_begin = false;
  bool check_end = false;
  for (int k = 0; k < size; ++k) {
    if (in_num[k] == out_num[k])
      ++count;
    else if (in_num[k] == out_num[k] + 1 && check_end == false) {
      _semi_end_index = k;
      check_end = true;
    } else if (in_num[k] + 1 == out_num[k] && check_begin == false) {
      _semi_begin_index = k;
      check_begin = true;
    } else
      return;
  }
  _euler_type = count == size ? EulerLoop : EulerPath;
}

void Resolve::workFlow() {
  if (_euler_type == EulerPath) {
    _graph.add_edge(_semi_end_index, _semi_begin_index);
  } else if (_euler_type == Null) {
    _ans = "No anser to output.";
    return;
  }

  // vector<vector<int>> graph = _graph.get_graph();
  EulerCore euler_work(_graph.get_graph());
  euler_work.init();
  euler_work.computeWay();

  vector<int> loop = euler_work.get_loop();
  reverse(loop.begin(), loop.end());
  vector<Person> persons = _persons.get_persons();
  if (_euler_type == EulerLoop) {
    for (int i = 0; i < loop.size() - 1; ++i) {
      _ans += persons[loop[i]].get_name() + " -> ";
    }
    _ans += persons[loop[loop.size() - 1]].get_name();
  } else {
    for (int i = 0; i < loop.size() - 1; ++i) {
      if (loop[i] == _semi_end_index && loop[i + 1] == _semi_begin_index) {
        for (int i_r = i + 1; i_r < loop.size() - 1; ++i_r) {
          _ans += persons[loop[i_r]].get_name() + " -> ";
        }
        for (int i_l = 0; i_l < i; ++i_l) {
          _ans += persons[loop[i_l]].get_name() + " -> ";
        }
        _ans += persons[loop[i]].get_name();
        return;
      }
    }
  }
}

}  // namespace Euler
