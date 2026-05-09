#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    
    size_t n,k; cin >> n >> k;

    vector<long long> v(n);
    long long maximum = -1e9, minimum = 1e9;
    for(size_t i = 0; i < n; ++i) {
      cin >> v[i];

      maximum = max(maximum,v[i]);
      minimum = min(minimum, v[i]);
    }

    // take the max and the minimum ni
    // then do a bs to calculate what is the best posibility



  }

  return 0;
}
