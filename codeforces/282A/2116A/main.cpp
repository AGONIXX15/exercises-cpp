#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t a,b,c,d; cin >> a >> b >> c >> d;
    size_t min_a = min(a,c);
    size_t min_b = min(b,d);
    if (min_a >= min_b) {
      cout << "Gellyfish" << '\n';
    } else {
      cout << "Flower" << '\n';
    }
  }

  return 0;
}
