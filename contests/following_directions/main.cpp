#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;

    string s; cin >> s;
    int x = 0, y = 0;

    bool flag = false;

    for(auto& c: s) {
      
      if(c == 'U') y++;
      else if(c=='D') y--;
      else if(c=='L') x--;
      else x++;

      if(x == 1 && y == 1) {
        flag = true;
        break;
      }
      
    }

    cout << ((flag) ? "YES":"NO") << '\n';
  }

  return 0;
}
