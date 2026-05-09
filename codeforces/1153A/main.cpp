#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int n, t;
  cin >> n >> t;

  int index = -1;
  long long value = LLONG_MAX;

  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;

    int k;
    if (t <= a) {
      k = 0;
    } else {
      k = static_cast<int>(ceil(1.0 * (t - a) / b));
    }

    long long new_value = a + 1LL * b * k;

    if (new_value < value) {
      value = new_value;
      index = i;
    }
  }

  cout << index << '\n';
  return 0;
}

