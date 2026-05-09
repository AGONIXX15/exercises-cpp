#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sum_digits(ll n) {
  ll d = 0;
  while (n) {
    d += n % 10;
    n /= 10;
  }
  return d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n; cin >> n;
  vector<int> sol = {1,    9,    36,   100,  225,  441,  784,  1296, 2025, 3025,
                     3969, 4761, 5329, 5625, 5625, 5329, 4761, 3969, 3025, 2025,
                     1296, 784,  441,  225,  100,  36,   9,    1};
  // for (ll i = 0; i < 1000; ++i) {
  //   for (ll j = 0; j < 1000; ++j) {
  //     ll result = sum_digits(i);
  //     if (result == sum_digits(j)) {
  //       sol[result]++;
  //     }
  //   }
  // }

  // for(ll i = 1e5; i < 1e6; ++i) {
  //   ll first = i % 1000;
  //   ll second = i / 1000;
  //   ll result = sum_digits(first);
  //   // cout << "i: " << i <<  " first: " << first << " second: " << second<<
  //   " result1: " << result<< '\n'; if(result == sum_digits(second)) {
  //     sol[result]++;
  //   }
  // }

  // cout << '{';
  // for (int i = 0; i < 28; ++i) {
  //   cout << sol[i] << (i == 27 ? "" : ", ");
  // }
  // cout << "}\n";
  cout << sol[n] << '\n';
  return 0;
}
