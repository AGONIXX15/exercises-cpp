#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T> void print_vector(const vector<T> &v) {
  for (const T &val : v) {
    cout << val << " ";
  }
  cout << '\n';
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> danger(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
      cin >> danger[i];
    }
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      cin >> edges[i].first >> edges[i].second;
    }
    vector<vector<int>> adyacent_list(n + 1);
    for (int i = 0; i < edges.size(); ++i) {
      adyacent_list[edges[i].first].push_back(edges[i].second);
      adyacent_list[edges[i].second].push_back(edges[i].first);
    }

    vector<int> parent(n + 1, -1);
    parent[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (const int &w : adyacent_list[u]) {
        if (parent[w] == -1) {
          parent[w] = u;
          q.push(w);
        }
      }
    }
  vector<ll> dp(n + 1, -1);
  for(int i = dp.size()-1; i > 0; --i){
    }
  }
  
  return 0;
}
