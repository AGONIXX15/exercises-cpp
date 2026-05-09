#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    long long n,m; cin >> n >> m;
  
    long long maximum = 0;
    bool is_normal = true;
    long long value; cin >> value;
    maximum = value;
    for(size_t i = 0; i < m-1; ++i) {
      long long new_value; cin >> new_value;

      if(value < new_value) {
        value = new_value;
      } else {
        is_normal = false;
      }

      maximum = max(maximum, value);
    }

    if(is_normal) {
      // cout << "maximum: " << maximum << '\n';
      cout << n - maximum + 1 <<'\n';
    } else {
      cout << 1 << '\n';
    }

    

    // cout << n - maximum + 1 << '\n';


  }

  return 0;
}
