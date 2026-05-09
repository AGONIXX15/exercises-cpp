#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  
  size_t n; cin >> n;
  vector<size_t> v(3);
  for(auto& val: v) cin >> val;
  
  size_t ans = 0;
  for(auto val: v) {
    if(n - val >= 2) {
      ans = max(ans, val);
    }
  }
  cout << ans << '\n';
}
