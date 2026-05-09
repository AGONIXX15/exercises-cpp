#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    ll n,k; cin >> n >> k;
    vector<ll> v(n);
    for(auto& val: v) {
      cin >> val;
      val = val + (val % (k+1))*k;
      cout << val << " ";
    }
    cout << '\n';
  


  }
  return 0;
}
