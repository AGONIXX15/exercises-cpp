#pragma once
#include <gramatic/State.hpp>
#include <queue>
#include <unordered_set>

class NFA {
  State *start;

  std::unordered_set<State *>
  epsilon_bfs(const std::unordered_set<State *> &paths) {
    std::queue<State *> q;

    std::unordered_set<State *> closure = paths;
    for (const auto &s : paths) {
      q.push(s);
    }

    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      for (const auto &s : node->epsilon) {
        if (!closure.count(s)) {
          closure.insert(s);
          q.push(s);
        }
      }
    }
    return closure;
  }

  bool matches(std::string &input) {

    std::unordered_set<State *> current;
    current.insert(start);
    current = epsilon_bfs(current);
    for (char c : input) {
      std::unordered_set<State *> next_states;
      for (auto s : current) {
        if (s->trans.count(c)) {
          for (auto next : s->trans[c]) {
            next_states.insert(next);
          }
        }
      }
      current = epsilon_bfs(next_states);
    }

    for (auto state : current) {
      if (state->accepting)
        return true;
    }
    return false;
  }
};
