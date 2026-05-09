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

ll n;
int total = 0;
ll minimum = 1e17;
// 3
//
// 111
void backtracking(ll i, ll product, ll suma, ll number) {

  if (product > 81)
    return;

  if (i == n) {
    if (product == suma) {
      total++;
      minimum = min(minimum, number);
    }
    return;
  }

  // number * 10 + d
  for (int d = 1; d <= 9; ++d) {
    backtracking(i + 1, product * d, suma + d, number * 10 + d);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  cin >> n;
  if (n == 1) {
    cout << "10 0\n";
    return 0;
  }

  backtracking(0, 1, 0, 0);
  cout << total << " " << minimum << '\n';
  return 0;
}
