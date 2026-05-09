#include <bits/stdc++.h>

using namespace std;

class UnionFind {
  vector<int> parent;
  vector<int> size;
  int N;

public:

  UnionFind(int n) {
    N = n;
    parent.resize(n);
    size.resize(n);
    for(int i = 0; i < N; ++i) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  // 0 1 2
  // 0 1 2
  // merge(1,2)
  // 0 2 2
  // 0 2 3 3
  // find(1)
  int find(int x) {
    // 2 != 1 p[1] = find(2)
    // 3 != 2 p[2] = find(3)
    // 3 != 3 False return p[3] === 3
    // reconstruction
    // p[2] = 3
    // p[1] = 3
    // return p[1] 
    if(parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    // already merge
    if(root_x == root_y) return;

    if(size[root_y] > size[root_x]) {
      parent[root_x] = root_y;
      size[root_y] += size[root_x];
    } else {
      parent[root_y] = root_x;
      size[root_x] += size[root_y];
    }

  }
  
  bool connected(int u, int v) {
    return find(u) == find(v);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n,q; cin >> n >> q;
  UnionFind un(n);

  for(size_t i = 0; i < q; ++i) {
    int op,u,v; cin >> op >> u >> v;
    if(!op) un.merge(u,v);
    else cout << (un.connected(u,v) ? 1: 0)  << '\n';
  }

  
  return 0;
}
