#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;

    vector<int> v(2*n);
    for(auto& val: v) cin >> val;

    vector<int> l(n,-1), r(n,-1);
    for(int i = 0; i < 2*n; ++i) {
      if(l[v[i]] == -1) l[v[i]] = i;
      else r[v[i]] = i;
    }

    int left = 2 * n, right = -1;
    int res = 0;
    for(int i = 0; i < n; ++i) {
      left = min(left,l[i]);
      right = max(right, r[i]);
      
      int length = right - left + 1;
      if(length == 2 *(i + 1)) {
        res = i + 1;
      }
    }
    cout << res << '\n';
  }
  return 0;

}
