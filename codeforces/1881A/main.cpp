#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n,m; cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;
    if(s1.size() > s2.size()) {
      cout << -1 << '\n';
      continue;
    }

    bool flag = false;
    string repeated = s1;
    int value = -1;

    for(int i = 0; i < 6; ++i) {
      if(repeated.find(s2) != string::npos) {
        value = i;
        break;
      }
      repeated.append(repeated);
    }
    cout << ((value != -1) ? value: -1) << '\n';
  }
  return 0;
}
