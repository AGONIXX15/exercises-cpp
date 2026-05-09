#include <bits/stdc++.h>

using namespace std;

double sqrt_by_me(long long sqrt_real) {
  double l  = 0, r = sqrt_real;

  while(l < r) {
    double mid = (l + r)/2;
    if((int)(mid * mid) == sqrt_real)  {
      return mid;
    } else if (mid * mid < sqrt_real) {
      l = mid + 1e-16;
    } else {
      r = mid - 1e-16;
    }
  }
  return r;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  long long sqrt_real; cin >> sqrt_real;
  cout << sqrt_by_me(sqrt_real) << '\n';

  return 0;
}
