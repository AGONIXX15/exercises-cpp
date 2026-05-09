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

bool can = false;

void backtracking(int i, vector<int> &sol, vector<vector<int>> &matr) {
  if (i == matr.size()) {
    cout << sol << '\n';
    can = true;
    return;
  }

  // cout << sol << '\n';
  int ones = 0;
  int negs = 0;
  vector<int> empty;

  for (int j = 0; j < 3; ++j) {
    int sign = matr[i][j] > 0 ? 1 : -1;
    int idx = abs(matr[i][j]);

    if (sol[idx] * sign == 1)
      ones++;
    else if (sol[idx] * sign == -1)
      negs++;
    else
      empty.push_back(idx * sign);
  }

  if (ones > 2 || negs > 1)
    return;
  cout << "empty: " << empty << '\n';
  int need_ones = 2 - ones;
  int need_neg = 1 - negs;
  if (empty.empty()) {
    if (need_ones == 0 && need_neg == 0)
      backtracking(i + 1, sol, matr);
    return;
  }

  function<void(int)> gen = [&](int pos) {
    if (pos == empty.size()) {
      if (need_ones + need_neg == 0)
        backtracking(i + 1, sol, matr);
      return;
    }
    int sign = empty[pos] > 0 ? 1 : -1;
    int idx = abs(empty[pos]);
    if (need_ones > 0) {

      int want = (sign == 1 ? 1 : -1);

      // ya existía
      if (sol[idx] != 0) {

        // compatible
        if (sol[idx] == want) {

          need_ones--;
          gen(pos + 1);
          need_ones++;
        }

      }

      // realmente vacío
      else {

        sol[idx] = want;

        need_ones--;

        gen(pos + 1);

        need_ones++;
        sol[idx] = 0;
      }
    }
    if (need_neg > 0) {

      int want = (sign == 1 ? -1 : 1);

      if (sol[idx] != 0) {

        if (sol[idx] == want) {
          need_neg--;
          gen(pos + 1);
          need_neg++;
        }
      }

      else {

        sol[idx] = want;

        need_neg--;

        gen(pos + 1);

        need_neg++;
        sol[idx] = 0;
      }
    }
  };
  gen(0);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> v(3, vector<int>(n));
    for (auto &row : v) {
      for (auto &val : row)
        cin >> val;
    }
    vector<vector<int>> matr(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        matr[i][j] = v[3 - j - 1][i];
      }
    }
    vector<int> sol(n + 1, 0);
    cout << matr << '\n';
    backtracking(0, sol, matr);
    cout << (can ? "YES" : "NO") << '\n';
    can = false;
    // if some arrangement we can have two 1 and one -1 we got it
    // 3!
    // 1! * 2! = 3
  }
  return 0;
}
