#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long long a, b, k;
    cin >> a >> b >> k;
    long long g = gcd(a, b);
    long long dx = a / g;
    long long dy = b / g;
    cout << ((dx <= k && dy <= k) ? 1 : 2) << '\n';
  }
}

