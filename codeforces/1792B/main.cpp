#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {

    ll a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    if (a1 == 0) {
      cout << "1\n";
      continue;
    }
    cout << a1 + min(a2,a3) * 2 + min(a1+1,abs(a2-a3) + a4) << '\n';
  }

  return 0;
}
