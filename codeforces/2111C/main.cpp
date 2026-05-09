#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t;
  cin >> t;
  size_t INF = 1e9;
  while (t--) {
    size_t n; cin >> n;
    vector<size_t> v(n,0);
    for(size_t i = 0; i < n; ++i) {
      size_t x; cin >> x;
      v[i] = x;
    }
    long long res = 1e9;
    for(size_t i = 0; i < n; ++i){

      long long cost = 0;

      int j = i-1;
      while(j >= 0) {
        if(v[j] == v[i]) {
          j--;
          continue;
        }

        cost += 1LL * (j+1) * v[i];
        break;
      }

      j = i+1;

      while(j < n) {
        if(v[j] == v[i]) {
          j++;
          continue;
        }

        cost += 1LL *(n - j) * v[i];
        break;
      }

      res = min(res, cost);
    }
    cout << res << '\n';
  }
  return 0;
}
