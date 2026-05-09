#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << '[';
  for(long long i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "":", ") ;
  }
  os << ']';
  return os;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n,m; cin >> n >> m;
    
    vector<vector<int>> v(n,vector<int>(m));
    
    for(size_t i = 0; i < n; ++i) {
      for(size_t j = 0; j < m; ++j) {
        cin >> v[i][j];
      }
    }
    
    // for(size_t i = 0; i < n; ++i) {
    //   cout << v[i] << '\n';
    // }
    
  }
  return 0;
}
