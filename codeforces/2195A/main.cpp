#include <bits/stdc++.h>


using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    bool flag = false;
    for(size_t i = 0; i < n; ++i) {
      int val; cin >> val;
      if(val == 67) {
        flag = true;
        break;
      }
    }

    cout << (flag ? "YES": "NO") << '\n';
  }
  return 0;
}
