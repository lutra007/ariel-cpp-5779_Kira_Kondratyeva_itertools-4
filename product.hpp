#pragma once
#include <string>
#include <sstream>

namespace itertools {
  template<typename Iterable>
  std::string product(const Iterable& iter1, const Iterable& iter2);
}