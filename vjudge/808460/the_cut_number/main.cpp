#include <bits/stdc++.h>

using namespace std;

int digits(int n) {
  int d = 0;
  while (n) {
    d++;
    n /= 10;
  }
  return d;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int d, k;
  cin >> d >> k;
  vector<int> v(k);
  for (auto &val : v)
    cin >> val;

  sort(v.begin(), v.end());
  vector<int> pow10(11, 1);
  for (int i = 1; i < 11; ++i) {
    pow10[i] = (pow10[i - 1] * 10) % d;
  }

  int count = 0;
  do {
    int ans = 0;
    for (int i = 0; i < k; ++i) {
      int ds = digits(v[i]);
      ans = (ans * pow10[ds] % d + v[i] % d) % d;
    }
    if(ans == 0) count++;
  } while (next_permutation(v.begin(), v.end()));
  cout << count << '\n';

  return 0;
}
