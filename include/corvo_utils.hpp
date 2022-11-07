#pragma once
#include <cmath>
#include <string>

using std::string;

template <typename T>
string format_num(T num, int digits) {
  long mult = std::pow(10, digits);
  T zeroed = std::floor(num * mult) / mult;
  string str = std::to_string(zeroed);
  str.erase( str.find_last_not_of('0') + 1, std::string::npos );
  str.erase( str.find_last_not_of('.') + 1, std::string::npos );
  return str;
}
