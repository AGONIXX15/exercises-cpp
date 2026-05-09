#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int x,y; cin >> x >> y;
    bool some_even = x % 2 == 0 || y % 2 == 0;
    if(x % 2 == 0 && y % 2 == 0) {
      cout << "Yes\n";
    } else if (some_even) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
