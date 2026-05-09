#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  string s; cin >> s;


  int count = 0;
  for(size_t i = 1; i < s.size(); ++i) {
    if(s[i-1] == s[i]) {
      ++count;
    } else {
      count = 0;
    }

    if(count >= 6) break;
    
  }

  if(count >= 6) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
