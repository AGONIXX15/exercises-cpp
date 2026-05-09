#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t n; cin >> n;
  double fence_perimeter = 0;
  while(n--) {
    int x,y,r; cin >> x >> y >> r;
    
    fence_perimeter += r*2*M_PI;
  }

  cout << fence_perimeter << '\n';
  return 0;
}
