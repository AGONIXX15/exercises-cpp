#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    vector<long long> v(n);
    for(auto& val: v) cin >> val;

    sort(v.begin(), v.end());


    long long maximum = -1e9;

    for(size_t i = 1; i < n; i += 2) {
      
      maximum = max(maximum, abs(v[i-1] - v[i]));
    }

    cout << maximum << '\n';
  }

  return 0;
}
