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

    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<int> v(n);
    for (auto &val : v)
      cin >> val;

    int min_sum = 0;
    for (int i = 0; i < v.size(); ++i) {
      cout << "best decision in i: " << i
           << (v[i] % p >= v[i] % q ? " p" : " q") << '\n';
      min_sum += min((v[i] % p), (v[i] % q));
    }
    cout << min_sum << '\n';
  }
  return 0;
}
