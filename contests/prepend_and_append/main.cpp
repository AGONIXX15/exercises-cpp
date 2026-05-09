#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    
    int l = 0, r = n-1;
    int distance = n;

    while(s[l] != s[r] && l < r) {
      l++;
      r--;
      distance -= 2;
    }

    cout << distance <<'\n';
  }





  return 0;
}
