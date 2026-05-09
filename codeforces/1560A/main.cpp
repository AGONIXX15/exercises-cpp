#include <bits/stdc++.h>

// a0 = 1
// a1 = 2
// a2 = 4
// an = an-1 + an-2 - an-3
// r³ = r² + r - 1
// r³ - r² - r + 1 = 0
// division sintetica por 1
// 1  -1  -1  1
//     1   0  -1 
// (r-1)(r² - 1) = 0
// r1 = 1  r2 = 1 r3 = -1
// an = Ar1^n + Bnr2^n + Cr3^n
// 1 = A + C
// 2 = A + B - C
// 4 = A + 2B + C
// 1 - A = C
// 2 = A + B -1 + A
// 2 = 2A + B -1
// 3 = 2A + B
// 3 -2A = B
// 4 =   6 -4A + 1
// 4 = 7 -4A
// -3 = -4A
// 3/4 = A
// 1 - 3/4 = C
// 1/4 = C
// 4 = 3/4 + 2B + 1/4
// 4 = 1 + 2B
// 3 = 2B
//
// an = (3/4 + 3/2n) + (1/4) * -1^n

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  size_t t; cin >> t;
  while (t--) {
    size_t v; cin >> v;
    size_t count = 0;
    size_t val = 0;
    while(count != v) {
      ++val;
      if(val % 10 != 3 && val % 3 != 0) count++;
    }
    cout << val << '\n';
  }
  return 0;
}
