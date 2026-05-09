#include <bits/stdc++.h>

using namespace std;
// n = d/l
// n*l = d
// d = (l-2) * 180
// n*l = (l-2) * 180
// 0 = -n*l + (l-2)*180
// 0 = -n*l + 180l - 360
// 0 = l(180 - n) - 360
// 360/(180 - n) =  l
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;
    int l = 360/(180 - n);
    if((l-2) * 180 / l == n) {
      cout << "YES" << '\n';
      continue;
    }
    cout << "NO" << '\n';
  }
}
