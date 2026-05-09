#include <bits/stdc++.h>

using namespace std;

bool squared(size_t n) {
  if(sqrt(n) == static_cast<int>(sqrt(n))) {
    return true;
  }
  return false;
}



int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    string s; cin >> s;
    if(!squared(n)) {
      cout << "No" << '\n';
      continue;
    }
    int squares_per_row = static_cast<int>(sqrt(n));
    bool flag = true;
    // cout << "squares_per_row: " << squares_per_row << '\n';
    for(int i = 0; i < n; ++i) {

      int r = i/squares_per_row; // current row
      int c = i % squares_per_row; // current column
      
      // cout << "r: " << r << '\n';
      // cout << "c: " << c << '\n';

      if((r == 0 || r == squares_per_row-1) && s[i] != '1') {flag = false;
}
      else if((c == 0 || c == squares_per_row-1) && s[i] != '1') { flag = false;
      }

      else if(s[i] == '1' && (c != 0 && c != squares_per_row-1 && r != 0 && r != squares_per_row-1))  {flag = false;}


      
      if(!flag) break;
    }

    if(flag) {
    cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
}
