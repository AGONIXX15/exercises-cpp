#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> v(n);
    for(auto& val: v) cin >> val;
    int count = 0;
    int l = 0;
    while(l < n && v[l] == 1) {
      l++;
      count++;
    }

    if(count == n) {
      cout << (n % 2 == 0 ? "Second": "First") << '\n';
    }
    else if(count % 2 == 0) cout << "First\n";
    else cout << "Second\n";

  }
  return 0;
}
