#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    bool ascending = false, descending = false;

    int last_val; cin >> last_val;
    bool flag = true;
    for(size_t i = 1; i < n; ++i) {
      int x; cin >> x;
      if(last_val <= x) {
        ascending = true;
      } else {
        if(descending) {
          flag = false;
        }
        descending = true;
      }
    }

    if(flag && ascending && !descending) {
      cout << "NO" << '\n';
    } else if(flag && ascending) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }

  return 0;
}
