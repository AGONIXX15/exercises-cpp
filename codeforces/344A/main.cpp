#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n; cin >> n;
  n -= 1;
  string s; cin >> s;
  char last = s[1];
  size_t ans = 1;
  while(n--) {
    cin >> s;
    if(last == s[0]) {
      ans++;
    }

    last = s[1];
  }
  cout << ans << '\n';

  return 0;
}
