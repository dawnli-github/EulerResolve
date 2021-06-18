/**
 * @file ReadFile.cpp
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief ReadFile
 * @version 0.1
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/ReadFile.h"

using namespace std;

namespace Euler {
void ReadFileBase::read_file(string file_path) {
  FILE* file;
  // limit string size < 20
  char str[20];
  string to_str;
  file = fopen(file_path.c_str(), "r");
  while (fscanf(file, "%s", str) != EOF) {
    to_str = str;
    _file_content.emplace_back(to_str);
  }
  fclose(file);
}
}  // namespace Euler