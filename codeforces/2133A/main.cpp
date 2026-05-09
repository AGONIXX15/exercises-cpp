#include <bits/stdc++.h>

using namespace std;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    unordered_set<int> s;
    bool flag = false;
    for(int i = 0; i < n; ++i) {
      int x; cin >> x;

      if(s.count(x)) {
        flag = true;
      }
      s.insert(x);
    }
    cout << ((flag) ? "YES":"NO") << '\n';
  }

  return 0;
}
