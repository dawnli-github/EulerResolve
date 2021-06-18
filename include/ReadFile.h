/**
 * @file ReadFile.h
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief ReadFile
 * @version 0.1
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <string>
#include <vector>

using namespace std;

#ifndef INCLUDE_READFILE_H_
#define INCLUDE_READFILE_H_

namespace Euler {
class ReadFileBase {
 public:
  ReadFileBase(){};
  virtual ~ReadFileBase() = default;

  void read_file(string file_path);
  vector<string> get_file_content() const { return _file_content; }

 private:
  vector<string> _file_content;
};
}  // namespace Euler

#endif