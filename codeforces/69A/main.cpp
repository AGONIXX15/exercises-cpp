#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  int x1 = 0,y1 = 0,z1 = 0;
  while(t--) {
    int x,y,z; cin >> x >> y >> z;
    x1 += x;
    y1 += y;
    z1 += z;
  }

  if(x1 == 0 && y1 == 0 && z1 == 0) {
    cout << "YES" << '\n';
    return 0;
  }
  cout << "NO" << '\n';
  return 0;
}
