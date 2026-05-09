#include <bits/stdc++.h>

using namespace std;

template <typename T, typename K>
ostream &operator<<(ostream &os, const unordered_map<T, K> &dct) {
  os << "{";
  for (const auto &p : dct) {
    os << p.first << " : " << p.second << '\n';
  }
  os << "}";
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i] << (i != v.size() - 1 ? ", " : "");
  }
  os << "]";
  return os;
}

using ll = long long;

using Graph = unordered_map<ll, unordered_set<ll>>;

void djikstra(Graph &graph, ll start_node, unordered_map<ll, ll> &products,
              size_t k, size_t n) {

  unordered_set<ll> visited;

  vector<ll> nodes_weight(n+1,1e9);
  nodes_weight[start_node] = 0;
  queue<pair<ll, ll>> q;
  q.push(make_pair(start_node, 0L));
  while (!q.empty()) {
    auto [current_node, weight] = q.front();
    q.pop();

    if(weight > nodes_weight[current_node]) continue;

    if(visited.count(current_node)) continue;

    for(auto neighbor: graph[current_node]) {
      if(weight+1 < nodes_weight[neighbor]) {
        nodes_weight[neighbor] = weight+1;
        q.push(make_pair(neighbor, weight+1));
      }
    }


  visited.insert(current_node);
}

vector<ll> prices(k + 1, -1e9);
for(size_t i = 1; i < n+1; ++i) {
  prices[products[i]] = max(prices[products[i]], nodes_weight[i]);
}



for (size_t i = 1; i < prices.size(); ++i) {
  cout << prices[i] << " ";
}
  cout << '\n';
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n, m, k;
  cin >> n >> m >> k;

  unordered_map<ll, ll> products;

  for (size_t i = 1; i <= n; ++i) {
    cin >> products[i];
  }

  // cout << products << '\n';

  // weight = 1 always
  unordered_map<ll, unordered_set<ll>> graph;
  for (size_t i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].insert(v);
    graph[v].insert(u);
  }
  djikstra(graph, 1, products, k, n);

  return 0;
}
