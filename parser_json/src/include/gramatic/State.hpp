#pragma once
#include <unordered_map>
#include <vector>

struct State {
  int id;

  std::unordered_map<char, std::vector<State *>> trans;

  std::vector<State *> epsilon;

  bool accepting = false;
};
