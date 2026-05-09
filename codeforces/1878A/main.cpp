#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t t;
  cin >> t;

  while (t--) {
    size_t n; cin >> n;
    size_t k; cin >> k;
    bool find = false;
    for(int i = 0; i < n; ++i) {
      int x; cin >> x;
      if (x == k) {
        find = true;
      }
    }
    cout << ((find) ? "YES": "NO") << endl;
  }
}
