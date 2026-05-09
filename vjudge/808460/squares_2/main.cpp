#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n; cin >> n;
  double area = 1;

  double black_area = 0;
  for(int i = 0; i < n; ++i) {
    black_area += area/2.0;
    area = area/4.0;
  }
  cout << fixed << setprecision(5) << black_area*100 << '\n';

  return 0;
}
