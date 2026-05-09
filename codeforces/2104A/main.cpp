#include <bits/stdc++.h>

using namespace std;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    bool flag = false;
    if ((a + b + c) % 3 != 0) {
    cout << ((flag) ? "YES": "NO") << '\n';
      continue;
    }

    int x = (a + b + c) / 3;
    
    cout << ((x >= b) ? "YES": "NO") << '\n';
  }
}
