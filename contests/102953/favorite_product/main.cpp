#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long k;
  cin >> n >> k;

  vector<int> vec(n);
  unordered_map<long long, long long> freq;

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
    freq[vec[i]]++;
  }

  long long count = 0;
  ///(a,a,a)
  // C(n, 3) = n(n-1)(n-2)/*r!
  // C(n, 2)*b = n(n-1)/*2!

  for (auto& [a, cnt_a] : freq) {
    for (auto& [b, cnt_b] : freq) {
      long long ab = 1LL * a * b;
      if (k % ab != 0) continue;

      long long c = k / ab;
      if (!freq.count(c)) continue;

      long long cnt_c = freq[c];

      if (a == b && b == c) {
        count += cnt_a * (cnt_a - 1) * (cnt_a - 2) / 6;
      } else if (a == b && b != c) {
        count += cnt_a * (cnt_a - 1) / 2 * cnt_c;
      } else if (a < b && b < c) {
        count += cnt_a * cnt_b * cnt_c;
      }
    }
  }

  cout << count << '\n';
  return 0;
}

