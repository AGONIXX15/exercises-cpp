#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    // f(bits) =  && bits <=10
    // f(bits) = 0 = 1
    // f(bits) = 1 = 0
    size_t sum = 0;
    for(size_t i = 0; i < n; ++i) {
      char c; cin >> c;
      if(c == '0') sum++;

      if(c == '1') {
        sum += n-1;
      }
    }
    cout << sum << '\n';
  }
}
