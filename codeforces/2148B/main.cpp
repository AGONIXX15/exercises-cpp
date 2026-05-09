#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n,m,x,y; cin >> n >> m >> x >> y;
    size_t v; 
    for(size_t i = 0; i < n; ++i) cin >> v;
    for(size_t i = 0; i < m; ++i) cin >> v;

    cout << n + m << '\n';

  }

  return 0;
}
