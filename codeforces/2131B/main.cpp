#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if(n == 2) {
      cout << -1 << " " << 2 << '\n';
      continue;
    }
    for (int i = 0; i < n - 2; ++i) {
      if (i % 2 == 0) {
        cout << -1 << " ";
      } else {
        cout << 2 << " ";
      }
    }
    // x = n/2 - 1
    // 2*x + y = n
    // y = n - 2*n/2
    //
    cout << n - 2*(n/2 - 1) << " " << -1 << '\n';
    // cout << -1/2 << '\n';

  }

  return 0;
}
