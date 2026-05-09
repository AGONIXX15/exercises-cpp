#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  os << '[';
  for (int i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size() - 1 ? "" : ", ");
  }
  os << ']';
  return os;
}

template <typename A, typename B>
ostream &operator<<(ostream &os, pair<A, B> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename K, typename T>
ostream &operator<<(ostream &os, unordered_map<K, T> &dct) {
  os << "{";
  int i = 0;
  for (auto &[key, value] : dct) {
    os << "{" << key << ": " << value << (++i != dct.size() ? "}, " : "}");
  }
  os << "}";
  return os;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> present;
    ll M = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      present.insert(x);
      M = max(M, (ll)x);
    }

    int m = 0;
    while (present.count(m))
      m++;

    if (m == 0) {
      cout << M * n << '\n';
      continue;
    }

    ll ans = M * n;

    if (M > m - 1) {
      ans += (ll)m * (m + 1) / 2 + (ll)m * (n - m - 1);
    } else {
      ans += (ll)(m - 1) * (m - 2) / 2 + m + (ll)m * (n - m);
    }

    cout << ans << '\n';
  }
  return 0;
}
