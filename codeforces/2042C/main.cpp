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
    int n, k;
    cin >> n >> k;
    vector<char> v(n);
    for (auto &val : v)
      cin >> val;
    int right_zeros = 0, right_ones = 0;
    for (int i = 1; i < n; ++i) {
      if (v[i] == '0')
        right_zeros++;
      else
        right_ones++;
    }

    int left_zeros = 0, left_ones = 0;
    for (int i = 0; i < n; ++i) {
    }
  }
  return 0;
}
