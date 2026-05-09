#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);


  size_t t; cin >> t;
  while(t--) {
    size_t n,m,h; cin >> n >> m >> h;
    
    vector<int> v(n);
    for(auto& val: v) {
      cin >> val;

    } 

    unordered_map<int,int> dct;
    // index: value
    for(size_t i = 0; i < m; ++i) {
        int b,c; cin >> b >> c;
        if (v[b-1] + dct[b] + c > h) dct.clear();
        else dct[b] += c;
    }

    for(size_t i = 0; i < n; ++i) {
      cout << v[i] + dct[i+1] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
