#include <bits/stdc++.h>

using namespace std;

class UnionFind {
  vector<int> parent;   
  vector<int> size;
  int N;

  UnionFind(int n) {
    N = n;
    parent.resize(n);
    size.resize(n);
    for(int i = 1; i <= N; ++i) {
      parent[i] = i;
      size[i] = 1;
    }
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  
  int n,m; cin >> n >> m;
  vector<int> cows(n);
  for(auto& val: cows) cin >> val;
  
  vector<tuple<int,int,int>> querys(m);
  for(auto& tup: querys) {
    cin >> get<0>(tup) >> get<1>(tup) >> get<2>(tup);
  }
  sort(querys.begin(), querys.end(), [](tuple<int,int,int>& a, tuple<int,int,int>& b){
    return get<2>(a) < get<2>(b);
  });

  // for(int i = 0; i < m; ++i) {
  //     cout << "("<< get<0>(querys[i])<< " " << get<1>(querys[i]) <<" " << get<2>(querys[i]) << ")\n";
  // }

  return 0;
}
