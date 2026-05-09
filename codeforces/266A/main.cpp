#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n; cin >> n;
  string s; cin >> s;
  size_t count = 0;
  for(size_t i = 0; i < n-1; ++i) {
    if(s[i] == s[i+1]) {
      count += 1;
    }
  }
    
  cout << count << '\n';
  return 0;
}
