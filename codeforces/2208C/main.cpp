#include <bits/stdc++.h>

using namespace std;

template <typename T, typename K>
ostream &operator<<(ostream &os, const pair<T, K> &p) {
  os << "(" << p.first << ", " << p.second << ')';
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '[';
  for (int i = 0; i < v.size(); ++i) {
    os << v[i] << (i != v.size() - 1 ? ", " : "");
  }
  os << ']';
  return os;
}


double brute_force(double s, int i, double result, vector<pair<int, int>> &v) {
  if (i >= v.size())
    return result;
  else if (s <= 0) return result;
  return max(brute_force(s, i + 1, result, v),
             brute_force(s * (1 - v[i].second / 100.0), i + 1,
                         result + (s * v[i].first), v));
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &p : v) cin >> p.first >> p.second;
    // sort(v.begin(), v.end(),Cmp());
    vector<double> dp(n+1,0);
    for(int i = n - 1; i >= 0; --i) {
      double p = v[i].second / 100.0;
      dp[i] = max(
        dp[i+1],
        v[i].first + (1 - p) * dp[i+1]
      );
    }
    cout << fixed << setprecision(10) << dp[0] << '\n';
  }

  return 0;
}
