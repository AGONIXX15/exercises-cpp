#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll f(int i, ll sum, ll cnt, ll a, vector<ll> &v,
     vector<vector<vector<ll>>> &dp) {
  if (i == v.size()) {
    if (cnt > 0 && sum == a * cnt)
      return 1LL;
    return 0LL;
  }
  if (dp[i][sum][cnt] != -1)
    return dp[i][sum][cnt];

  dp[i][sum][cnt] =
      f(i + 1, sum + v[i], cnt + 1, a, v, dp) + f(i + 1, sum, cnt, a, v, dp);

  return dp[i][sum][cnt];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  ll n, a;
  cin >> n >> a;
  vector<ll> v(n);
  int sum = 0;
  for (auto &val : v) {
    cin >> val;
    sum += val;
  }
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(sum, vector<ll>(n, -1)));

  cout << f(0, 0LL, 0LL, a, v, dp) << '\n';
  return 0;
}
