/**
 * @file Person.cpp
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Person.h"

using namespace std;

namespace Euler {
void Persons::init_persons() {
  vector<string> file_content = get_file_content();
  int person_num = file_content.size() / 3;
  // resize
  _persons.resize(person_num);
  // add person
  for (int i = 0; i < person_num; ++i) {
    _persons[i].set_index(stoi(file_content[3 * i]));
    _persons[i].set_name(file_content[3 * i + 1]);
    _persons[i].set_year(stoi(file_content[3 * i + 2]));
  }
}
}  // namespace Euler