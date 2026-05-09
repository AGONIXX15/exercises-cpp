#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t a,b,c,d; cin >> a >> b >> c >> d;

    if(a == b && a == c && a == d) {
      cout << "YES" << '\n';
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
