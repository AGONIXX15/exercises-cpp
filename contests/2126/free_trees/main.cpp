#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t;
  cin >> t;
  while (t--) {
    size_t n, q;
    cin >> n >> q;

    unordered_map<int, int> color; 
    unordered_map<int, unordered_map<int, int>> graph;

    for (int i = 1; i <= n; ++i) {
      cin >> color[i];
    }

    long long total_cost = 0;
    for (int i = 1; i < n; ++i) {
      int u, v, c;
      cin >> u >> v >> c;
      graph[u][v] = c;
      graph[v][u] = c;
      if (color[u] != color[v]) {
        total_cost += c;
      }
    }

    while (q--) {
      long long node, new_color;
      cin >> node >> new_color;
      if (color[node] == new_color) {
        cout << total_cost << '\n';
        continue;
      }

      long long last_cost = 0, current_cost = 0;
      for (auto& [neighbor, cost] : graph[node]) {
        if (color[neighbor] != color[node]) last_cost += cost;
        if (color[neighbor] != new_color) current_cost += cost;
      }

      color[node] = new_color;
      total_cost = total_cost - last_cost + current_cost;
      cout << total_cost << '\n';
    }
  }
  return 0;
}
