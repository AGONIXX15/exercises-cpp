#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    ll a,b,c; cin >> a >> b >> c;
    ll sum = 0;
    ll min_3_ops = min({a,b,c});
    sum += 7*min_3_ops;
    a -= min_3_ops;
    b -= min_3_ops;
    c -= min_3_ops;
    // h with t 5
    ll k = min (b,a);
    sum += k * 5;
    b -= k;
    a -= k;

    sum += a / 2 * 5;
    if(a % 2 && b > 0)  {
      sum += 5;
      b--;
    }
    
    sum += b * 3;
    sum += c * 3;
    cout << sum << '\n';

  }
  return 0;
}
