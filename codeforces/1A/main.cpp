#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n,m; cin >> n >> m;
  size_t a; cin >> a;
  // area = k * other_area
  // k = area/other_area
  // x = x1 * k
  // x/x1 = k
  // y = y1 * k
  // y/y1 = k1

  cout << static_cast<long long>(ceil(1.0* m/a)*ceil(1.0 * n/a)) << '\n';

  return 0;
}
