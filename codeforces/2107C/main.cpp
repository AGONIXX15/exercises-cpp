#include <bits/stdc++.h>

using namespace std;


using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  while(t--) {
     ll n,k; cin >> n >> k;
    string bin; cin >> bin;

    vector<ll> v(n);
    
    ll curr = 0, maximum = 0;
    for(int i = 0; i < n; ++i) {
      cin >> v[i];
      if(bin[i] == '0') v[i] = -1e13;
      curr = max(0LL, curr +v[i]);
      maximum = max(curr, maximum);
    }
    if(maximum > k) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
  }

}
