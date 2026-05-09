#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &val : v) cin >> val;
    
    //|v - k*z = x // x + k*z = y
    // v - x = k*z  // (y - x)/k = z
    // (v - x)/k = z
    // z*k = v - x
    bool flag = true;
    for(int i = 0; i < n; ++i) {
      int x; cin >> x;
      // z1 y z2 son numeros enteros
      int z1 = (v[i] - x)/k, z2 = (x - v[i])/k;

      cout << "z1 : " << z1 << '\n';
      cout << "z2 : " << z2 << '\n';
      if(abs(v[i] - k*z1) == x || v[i] + k*z2 == x) {
        cout << "continuando" << '\n';
        continue;
      } else {
        flag = false;
      }
    }
    cout << ((flag) ? "YES": "NO") << '\n';
  }
  return 0;
}
