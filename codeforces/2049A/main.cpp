#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> v(n);
    for(auto& val: v) cin >> val;
    bool flag = true;
    bool has_zero = false;
    int zeros = 0;
    for(int i = 0; i < n; ++i) {
      if(v[i] != 0) flag = false;
      if(v[i] == 0) 
      { has_zero = true; zeros++; }
    }
    if(flag) {
      cout << "0\n";
      continue;
    } else if(!has_zero) {
       cout << "1\n";
      continue;
    }
    if((zeros == 2 && v[0] + v[n-1] == 0) || (zeros == 1 && v[0] == 0) || (zeros == 1) && v[n-1] == 0) {
      cout << "1\n";
      continue;
    } else cout << "2\n";
  }
  return 0;
}
