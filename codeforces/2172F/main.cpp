#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);


  size_t n; cin >> n;

  vector<ll> v(n);
  ll minimum = 1e9;
  for(size_t i = 0; i < n; ++i)  {
    cin >> v[i];
    minimum = min(v[i], minimum);
  }

  ll cost = 0;
  for(size_t i = 0; i < n; ++i) {
    if(v[i] == v[0]) continue;


    if(v[i] >= v[0]*2 || v[i] <= v[0]/2) cost += 1;
    else {
      size_t value = v[0];
      for(size_t j = v[0]+1; j <= v[i]; ++j) {
          value = min(value, gcd(j,value));
      }
      cost += value;
    }


  }

  cout << cost << '\n';
  
  return 0;
}
