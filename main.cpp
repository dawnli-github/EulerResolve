/**
 * @file main.cpp
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief main
 * @version 0.1
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

#include "include/EulerResolve.h"

using namespace std;

int main() {
  // init
  Euler::Graph test_graph;
  Euler::Persons test_persons;
  test_graph.read_file("./input/relationship.txt");
  test_persons.read_file("./input/people.txt");
  test_graph.init_graph();
  test_persons.init_persons();
  // run
  Euler::Resolve test(test_graph, test_persons);
  test.init();
  test.workFlow();
  // get euler type
  string type = test.getEulerType();
  // get answer
  string ans = test.getAnser();
  cout << "This graph's Eulertype: " << type << endl
       << "Answer: " << ans << endl;
  return 0;
}