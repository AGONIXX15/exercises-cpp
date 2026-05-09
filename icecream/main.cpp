#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);


  ios::sync_with_stdio(0);

  size_t t; cin >> t;

  while(t--) {
    int n,k; cin >> n >> k;



    if(k * 7 < n) {
      // n - k * 7 - 14*z  = 0
      //n - k * 7 = 14z
      //
      // ceil((n - k * 7) / 14 ) = z
      cout << ceil((n-k*7)/14.) << '\n';
    } else {
      cout << "0" << '\n';
    }

    
  }

  return 0;
}
