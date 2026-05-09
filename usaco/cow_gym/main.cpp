#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  freopen("gymnastics.in","r", stdin);
  freopen("gymnastics.out","w", stdout);
  int n,k; cin  >> n >> k;
  vector<vector<int>> v(k,vector<int>(n));
  for(auto& row: v) {
    for(auto& val: row) cin >> val;
  }

  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      for(int r = 0; r < k; ++r) {
        if()
      }
    }
  }
  return 0;
}
