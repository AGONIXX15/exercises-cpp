#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  size_t n,q; cin >> n >> q;
  
  unordered_map<int,unordered_set<int>> dct;


  for(size_t i = 0; i < q; ++i) {
    int t; cin >> t;
    int u,v; cin >> u >> v;
    if(t == 0) {
      dct[u].insert(v);
    } else {
      cout << dct[u].count(v) << "\n";
    }

  }
  

  return 0;
}
