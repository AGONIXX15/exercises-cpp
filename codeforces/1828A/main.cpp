#include <bits/stdc++.h>

using namespace std;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n; 
    for(int i = 1; i <= n; ++i) {
      cout << 2*i << ' ';
    }
    cout << '\n';
  }
  return 0;
}
