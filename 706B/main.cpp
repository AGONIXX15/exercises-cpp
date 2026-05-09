#include <algorithm>
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

int upper_bound(vector<int> &v, int l, int r, int val) {
  while (l <= r) {
    int mid = (l + r) / 2;

    if (val >= v[mid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &val : v)
    cin >> val;
  int q;
  cin >> q;

  sort(v.begin(), v.end());
  int total = 0;
  for (int i = 0; i < q; ++i) {
    int val;
    cin >> val;
    total = upper_bound(v, 0, v.size() - 1, val);
    cout << total << '\n';
  }
  return 0;
}
