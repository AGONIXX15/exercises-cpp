#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  size_t n, m;
  cin >> n >> m;

  vector<string> spotty(n);
  for (auto &str : spotty) cin >> str;

  vector<string> plain(n);
  for (auto &str : plain) cin >> str;


  unordered_set<string> st;
  int count = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      for (int k = j + 1; k < m; ++k) {
        unordered_set<string> st;
        for(int p = 0; p < n; ++p) {
          string s;
          s += plain[p][i];
          s += plain[p][j];
          s += plain[p][k];
          st.insert(s);
        }
        
        bool ok = true;
        for(int p = 0; p < n; ++p) {
          string s;
          s += spotty[p][i];
          s += spotty[p][j];
          s += spotty[p][k];
          if(st.count(s)) {
            ok = false;
            break;
          }
        }
        if(ok) count++;
      }
    }
  }
  cout << count << '\n';

  return 0;
}
