#include <bits/stdc++.h>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  if (v.size() == 0) {

    return os << "[]";
  }

  os << "[";
  for (size_t i = 0; i < v.size() - 1; ++i) {
    os << v[i] << ", ";
  }
  os << v[(v.size() - 1)];
  os << "]";
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  // prefix sum

  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;
    vector<long long> v(2 * n, 0);

    for (auto &val : v)
      cin >> val;
    // O(n * k)

    // a1 * 1 + a2 * 2 + ... ak * k


    // O(n²)
    for (size_t k = 1; k <= n; ++k) {
      long long sum = 0;

      for (size_t i = 0; i < k; ++i)
        sum -= v[i];

      bool flag = false;
      for (size_t i = k; i < 2 * n-k; ++i) {

        sum += (flag) ? -v[i] : v[i];
        // if(flag) {
        //   cout << "minus " << -v[i] << '\n';
        // } else {
        //   cout << "plus " << v[i] << '\n';
        // }

        flag = !flag;
      }

      for(size_t i = 2*n-k; i < 2*n; ++i) sum += v[i];

      cout << sum << ' ';
    }
    cout << '\n';
  }

  // 4 5 6 9 13 15
  // n = 3
  // k = 2

  return 0;
}
