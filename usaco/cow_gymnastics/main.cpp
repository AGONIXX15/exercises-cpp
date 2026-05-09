#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);
  size_t k,n; cin >> k >> n;
  vector<vector<ll>> v(k,vector<ll>(n));

  for(auto& vec: v) {
    for(auto& val: vec) cin >> val;
  }

  ll count = 0;
  for(ll i = 0; i < n; ++i) {
    for(ll j = i+1; j < n; ++j) {
      bool flag1 = false;
      bool flag2 = false;
      bool _false = false; 
      for(ll p = 0; p < k; ++p) {
        if(v[p][i] > v[p][j])  flag1 = true;
        else if(v[p][j] > v[p][i]) flag2 = true;
        else {
          _false = true;
          break;
        }
      }
      if(!_false && flag1 ^ flag2)count++;
    }
  }
  cout << count << '\n';
  return 0;
}
