#include <iostream>
#include <queue>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace algo {
template <typename T> using set = std::unordered_set<T>;
using string = std::string;
template <typename T, typename K> using dict = std::unordered_map<T, K>;
template <typename T> using vec = std::vector<T>;
template <typename T> using queue = std::queue<T>;
template <typename T1, typename T2> using pair = std::pair<T1, T2>;

set<string> language(set<char> v, set<char> t, dict<string, vec<string>> p,
                     string s, int max_iterations) {
  set<string> ans;
  queue<pair<string, int>> q;
  q.push({s, 0});
  while (!q.empty()) {
    auto [new_str, level] = q.front();
    q.pop();
    if (std::all_of(new_str.begin(), new_str.end(), [&t](char x) {
          auto it = t.find(x);
          return it != t.end();
        })) {
      ans.insert(new_str);
    }

    if (level >= max_iterations) {
      return ans;
    }

    for (auto it = p.begin(); it != p.end(); ++it) {
      std::regex pattern(it->first);
      auto start =
          std::sregex_iterator(new_str.begin(), new_str.end(), pattern);
      auto end = std::sregex_iterator();
      for (auto iterator = start; iterator != end; ++iterator) {
        std::smatch match = *iterator;
        int match_start = match.position();
        int match_end = match_start + match.length();
        for (auto val : it->second) {
          string str =
              new_str.substr(0, match_start) + val + new_str.substr(match_end);
          q.push({str, level + 1});
        }
      }
    }
  }
  return ans;
}

} // namespace algo
//

void print_set(std::unordered_set<std::string>& s){
  std::cout << "{";
  for(auto it = s.begin(); it != s.end(); ++it){
    auto temp = it;
    if (++temp == s.end()){
      std::cout << "'" << *it << "'";
      continue;
    }
    std::cout << "'" << *it << "'" << ", ";
  }
  std::cout << "}" << std::endl;
}



int main() {
  using namespace algo;
  // v = {'a', 'b', 'A', 'B', 'S'}
  // t = {'a', 'b'}
  // s = 'S'
  // p = {'S': ['ABa'], 'A': ['BB'], 'B': ['ab'], 'AB': ['b']}

  set<char> v = {'a', 'b', 'A', 'B', 'S', '1', '0'};
  set<char> t = {'a', 'b', '1', '0'};
  string s = "S";
  dict<string, vec<string>> p = {
      {"S", {"ABSa","10", ""}}, {"A", {"BB"}}, {"B", {"ab"}}, {"AB", {"b"}}};
  set<string> ans = language(v, t, p, s, 20);
  print_set(ans);
}
