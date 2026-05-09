#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  // m*n - m - n

  int sum = 0;
  for(int i = 1; i < 6; ++i) {
    for(int j = 1; j < 6; ++j) {
      int x; cin >> x;
      if(x == 1) {
        sum = abs(i-3) + abs(j-3);
      }
    }
  }
  cout << sum << '\n';
  return 0;
}
