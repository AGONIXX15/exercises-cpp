#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n, k;
    cin >> n >> k;
    // n-1 numeros cada x vuelta = ceil(k/(n-1))*n-1-abs()

    size_t value = ceil(1. * k / (n - 1)) * n;
    cout << static_cast<long long>(value - 1 - abs( k - ceil(1. * k / (n - 1)) * (n - 1))) << '\n';
  }

  return 0;
}
