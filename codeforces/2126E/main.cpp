#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    vector<size_t> v1(n);
    for(size_t i = 0; i < n; ++i) cin >> v1[i];

    vector<size_t> v2(n);
    for(size_t i = 0; i < n; ++i) cin >> v2[i];

    size_t index = 0;
    bool change = false;
    size_t last_gcd = v1[0];
    bool is_yes = true;
    while(index < n) {
      if(change) {
    
      size_t result = gcd(last_gcd,  v2[index]);
        cout << "result == last_gcd" << '\n';
        cout <<  result << " " << last_gcd << '\n';
      if(result == last_gcd) {
        last_gcd = v2[index];
        index++;
      } else {
          is_yes = false;
          break;
      }
        continue;
      }
      size_t result = gcd(last_gcd,  v1[index]);
      if(result == v1[index]) {
        last_gcd = v1[index];
        index++;
      } else {
        change = true;
      }
    }

    cout << ((is_yes) ? "YES": "NO") << '\n';
  }

  return 0;
}
