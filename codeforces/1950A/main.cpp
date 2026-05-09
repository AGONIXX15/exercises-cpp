#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    
    int a,b,c; cin >> a >> b >> c;

    if(a < b && b < c) {
      cout << "STAIR" << '\n';
    } else if(a < b && c < b) {
      cout << "PEAK" << '\n';
    } else {
      cout << "NONE" << '\n';
    }
  }

  return 0;
}
