#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v) cin >> val;

    int minimum = 0;
    int maximum = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if(v[i] > x) {
        maximum += v[i] - x;
      } else if (v[i] < x) {
        minimum += x - v[i];
      }
    }
    // 
    // x -= 1
    // y -= 1
    // step
    //
    // cout << "maximum: " << maximum << '\n';
    // cout << "minimum: " << minimum << '\n';
    cout << maximum + 1 << '\n';
  }

  return 0;
}
