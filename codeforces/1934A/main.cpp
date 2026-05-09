#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &val : v)
      cin >> val;

    // ll max_value = -1e7;
    // for (int i = 0; i < n; ++i) {
    //   for (int j = i + 1; j < n; ++j) {
    //     for (int k = j + 1; k < n; ++k) {
    //       for (int l = k + 1; l < n; ++l) {
    //         ll value =
    //             abs(v[i] - v[j]) + abs(v[j] - v[k]) + abs(v[k] - v[l]) +
    //             abs(v[l] - v[i]); 
    //         cout << "i: " << i << " j: " << j << " k: " << k << " l: " << l <<'\n';
    //         cout << "value: " << value << " max_value: " << max_value << '\n';
    //         max_value = max(max_value, value);
    //       }
    //     }
    //   }
    //  
    // }
    sort(v.begin(), v.end());
    // a -> b -> c -> d -> a
    cout << abs(v[0] - v[n-2]) + abs(v[n-2] - v[1]) + abs(v[1] - v[n-1]) + abs(v[n-1] - v[0]) << '\n';
  }
  return 0;
}
