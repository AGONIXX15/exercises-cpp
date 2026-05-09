#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    size_t sum = 0;
    for(size_t i = 0; i < n; ++i) {
      size_t x; cin >> x;
      sum += (x == 0) ? 1: x;
    }
    cout << sum << '\n';
  }


  return 0;
}
