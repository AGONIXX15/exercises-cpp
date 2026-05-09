#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    int first; cin >> first;
    int second; cin >> second;

    for(size_t i = 2; i < n; ++i) {
      int x;
      cin >> x;
    }

    cout << min(first * (int)n, first + second) << '\n';
  }
  return 0;
}
