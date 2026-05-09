#include <bits/stdc++.h>

using namespace std;
void print_graph(const unordered_map<int,unordered_set<int>>& graph) {
  for(auto row: graph) {
    cout << "{" << row.first << ":";
    cout << "{";
    for(auto val: row.second){
      cout << val << ", ";
    }
    cout << "}";
    cout << "}";
    cout << '\n';
  }
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
  size_t n; cin >> n;
  unordered_map<int,unordered_set<int>> graph;

  for(int i = 0; i < n-1; ++i) {
    int u,v; cin >> u >> v;
    graph[u].insert(v);
    graph[v].insert(u);
  }
  print_graph(graph);

  int count = 0;
  for(int i = 1; i <= n; ++i) {
    if(graph[i].size() == 1) {
      cout << i << '\n';
      count++;
    }
  }
  cout << count << '\n';


  return 0;
}
