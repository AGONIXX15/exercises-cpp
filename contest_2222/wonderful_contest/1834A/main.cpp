#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int minus = 0;
    for(int i = 0; i < n; ++i) {
      int x; cin >> x;
      if(x == -1) minus++;
    }
    int ones = n - minus;

    if(ones > minus) {
      cout << minus % 2 << '\n';
    } else {
      // ones + minus >= 0
      // ones - minus = 0
      // 
      // ones >= minus
      cout << minus - ones + minus % 2 << '\n';
    }
    
  }

  return 0;
}
