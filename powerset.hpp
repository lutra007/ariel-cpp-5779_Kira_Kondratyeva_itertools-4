#pragma once
#include <string>
#include <sstream>

namespace itertools {
  template<typename Iterable>
  std::string powerset(const Iterable& iterable);
}