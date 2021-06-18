/**
 * @file Person.h
 * @author Dawn Li (dawnli619215645@gmail.com)
 * @brief Person
 * @version 0.1
 * @date 2021-06-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <array>
#include <string>

#include "ReadFile.h"

using namespace std;

#ifndef INCLUDE_PERSON_H_
#define INCLUDE_PERSON_H_

namespace Euler {
class Person {
 public:
  Person(){};
  Person(const Person& other)
      : _index(other._index), _name(other._name), _year(other._year) {}
  Person(const Person&& other)
      : _index(other._index), _name(other._name), _year(other._year) {}
  ~Person() = default;

  // get imformation
  int get_index() const { return _index; }
  string get_name() const { return _name; }
  int get_year() const { return _year; }
  // set imformation
  void set_index(const int index) { _index = index; }
  void set_name(const string name) { _name = name; }
  void set_year(const int year) { _year = year; }

 private:
  int _index;
  string _name;
  int _year;
};

class Persons : public ReadFileBase {
 public:
  Persons() = default;
  ~Persons() = default;
  // init
  void init_persons();
  // get
  vector<Person> get_persons() const { return _persons; }

 private:
  vector<Person> _persons;
};  // namespace Euler
}  // namespace Euler

#endif