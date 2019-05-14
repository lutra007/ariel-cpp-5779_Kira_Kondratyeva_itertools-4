#pragma once
#include <string>
#include <sstream>

namespace itertools {
  template <typename Iterable>
  std::string chain(const Iterable& iter1, const Iterable& iter2);
}