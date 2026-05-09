#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    int maximum = -1e5;
    for(size_t i = 0; i < n; ++i) {
      int val; cin >> val;
      maximum = max(val, maximum);
    }

    cout << maximum * n << '\n';
  }

  return 0;
}
