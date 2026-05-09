#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  


  string code = "codeforces";
  unordered_set<char>s(code.begin(),code.end());
  size_t n; cin >> n;

  while(n--) {
    char c; cin >> c;

    if(s.count(c)) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }


  return 0;
}
