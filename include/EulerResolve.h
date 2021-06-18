/**
 * @file EulerResolve.h
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief Euler Resolve
 * @version 0.1
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <array>
#include <string>
#include <vector>

#include "Graph.h"
#include "Person.h"

using namespace std;

#ifndef INCLUDE_EULERRESOLVE_H_
#define INCLUDE_EULERRESOLVE_H_

namespace Euler {

enum EulerType : uint8_t {
  EulerLoop,  // have Euler Loop
  EulerPath,  // have Euler Path
  Null        // no anser
};

const vector<string> euler_type_list{"EulerLoop", "EulerPath", "Null"};

struct edge {
  edge() {
    to = 0;
    next = 0;
  }
  int to;
  int next;
};

class EulerCore {
 public:
  explicit EulerCore(vector<vector<int>> graph) : _graph(graph) {}
  ~EulerCore() = default;

  void init();
  void computeWay();
  vector<int> get_loop() const { return _loop; }

 private:
  void addEdge(int x, int y);

  vector<vector<int>> _graph;
  vector<edge> _graph_edge;

  int _tot;
  int _top;
  vector<int> _head;
  vector<int> _stack;
  vector<bool> _visit;
  vector<int> _loop;
};

class Resolve {
 public:
  explicit Resolve(const Graph graph, const Persons persons)
      : _graph(graph), _persons(persons) {
    _euler_type = Null;
  }
  ~Resolve() = default;

  void init();
  void workFlow();

  string getEulerType() const { return euler_type_list[_euler_type]; }
  string getAnser() const { return _ans; }

 private:
  Graph _graph;
  Persons _persons;
  EulerType _euler_type;
  int _semi_begin_index;
  int _semi_end_index;
  string _ans;
};
}  // namespace Euler

#endif