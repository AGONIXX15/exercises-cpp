#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool is_number(ll n) {
  int sum = 0, product = 1;
  while (n != 0) {
    int digit = n % 10;
    sum += digit;
    product *= digit;
    n /= 10;
  }
  return sum == product;
}

// digit dp
// fibonacci(3) = fibonacci(2) +fibonacci(1)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n;
  // cin >> n;
  // cout << is_number(100) << '\n';

  vector<pair<ll, ll>> v = {{10, 0},       {1, 22},         {6, 123},
                            {12, 1124},    {40, 11125},     {30, 111126},
                            {84, 1111127}, {224, 11111128}, {144, 111111129}};

  for (int i = 2; i < 10; ++i) {
    int count = 0;
    int minimum = -1;
    int limit = pow(10, i);
    for (int j = pow(10, i - 1); j < limit; ++j) {
      if (is_number(j)) {
        count++;
        if (minimum == -1)
          minimum = j;
      }
    }
    cout << count << " " << minimum << '\n';
  }
  // for(int i = 0; i < 9; ++i) {
  //
  // cout << v[i].first << " " << v[i].second << '\n';
  // }
  // cout << v[n - 1].first << " " << v[n - 1].second << '\n';
  return 0;
}
