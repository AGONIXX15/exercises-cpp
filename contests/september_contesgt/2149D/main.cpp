#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;
    string s;
    cin >> s;

    long long minimum = 1e9;
    long long sum = 0;
    for (size_t i = 0; i < n; ++i) {
      if (s[i] == 'a') {
        continue;
      }
      sum++;
    }
    minimum = min(minimum, sum);

    sum = 0;
    for (long long i = n - 1; i >= 0; --i) {

      if (s[i] == 'a') continue;
      sum++;
    }

    minimum = min(minimum,sum);
    cout << minimum << '\n';
  }

  return 0;
}
