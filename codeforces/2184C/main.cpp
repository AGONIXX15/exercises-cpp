#include <bits/stdc++.h>


using namespace std;

using ll = long long;

int main() {

  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {

    size_t n,k; cin >> n >> k;

    if(n == k) {
      cout << 0 << '\n';
      continue;
    }


    // select always the odd branch
    //

    int count = 1;
    while(n != 0) {
      double num = 1.0 * n / 2; 
      ll x = ceil(num);
      ll y = floor(num);

      if(x == k || y == k) {
        cout << count << '\n';
        break;
      }

      // select the number
      n = (x % 2 == 1) ? x: (y % 2 == 1) ? y: x;



      if(n < k) {
        cout << -1 << '\n';
        break;
      }
        count++;
    }
    

  }
  return 0;
}
