#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    int open=0, close = 0;
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] == '(') open++;
      else if(s[i] == ')') close++;
    }

    cout << (open == close ? "YES": "NO") << '\n';
  }
  return 0;
}
