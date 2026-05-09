#include <bits/stdc++.h>

using namespace std;

int main() {

  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  size_t t; cin >> t;

  while (t--) {
    size_t a; cin >> a;
    size_t b; cin >> b;
    if(a == b) {
      cout << 0 << '\n';
      continue;
    }
      
    int value = a - b;
    
    size_t op =(a%10 == b%10) ? abs(value)/10: abs(value)/10 + 1;
    cout << op << '\n';
  }
}
