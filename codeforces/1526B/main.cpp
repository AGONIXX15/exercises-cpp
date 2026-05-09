#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    int n; cin >> n;
    if(n > 1099)  {
      cout << "YES" << '\n';
      continue;
    }
    bool flag = false;
    for(int i = 0; i <= 100; ++i) {
      if(n - i*11 >= 0 && (n - i*11) % 111 == 0) {
        flag = true;
        break;
      }
    }

    cout << ((flag) ? "YES" : "NO") << '\n';
  }
}
