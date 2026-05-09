#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  os << '[';
  for (int i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size() - 1 ? "" : ", ");
  }
  os << ']';
  return os;
}

template <typename A, typename B>
ostream &operator<<(ostream &os, pair<A, B> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename K, typename T>
ostream &operator<<(ostream &os, unordered_map<K, T> &dct) {
  os << "{";
  int i = 0;
  for (auto &[key, value] : dct) {
    os << "{" << key << ": " << value << (++i != dct.size() ? "}, " : "}");
  }
  os << "}";
  return os;
}

using Graph = unordered_map<int, unordered_set<int>>;
bool can_visit(Graph &graph, int u, int v) {
  unordered_set<int> visited;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    auto node = q.front();
    visited.insert(node);
    q.pop();
    if (node == v)
      return true;
    for (auto new_nodes : graph[node]) {
      if (!visited.count(new_nodes)) {
        q.push(new_nodes);
      }
    }
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(m);
  unordered_map<int, unordered_set<int>> dct;
  for (int i = 0; i < m; ++i) {
    cin >> v[i].first >> v[i].second;
    dct[v[i].first].insert(v[i].second);
    dct[v[i].second].insert(v[i].first);
  }

  int count = 0;
  for (int i = 0; i < m; ++i) {
    dct[v[i].first].erase(v[i].second);
    dct[v[i].second].erase(v[i].first);
    if (!can_visit(dct, v[i].first, v[i].second))
      count++;
    dct[v[i].first].insert(v[i].second);
    dct[v[i].second].insert(v[i].first);
  }
  cout << count << '\n';

  return 0;
}
