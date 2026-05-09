#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t n; cin >> n;
  int count = 0;
  for(size_t i = 0; i < n; ++i) {
    string s; cin >> s;
    if(s[0] == '+' || s[2] == '+') {
      ++count;
    } else --count;
  }
  cout << count << '\n';

  return 0;
}
