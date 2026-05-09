#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll brute_force(ll right, ll left, vector<ll> &v, ll index) {
  if (index < 0 || index >= v.size())
    return 1e18;

  return min(min(abs(right - left),
                 brute_force(right + v[index], left - v[index], v, index + 1)),
             brute_force(right, left, v, index + 1));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  size_t n;
  cin >> n;
  vector<ll> v(n);

  ll sum = 0;
  for (auto &val : v) {
    cin >> val;
    sum += val;
  }

  cout << brute_force(0, sum, v, 0) << '\n';
  return 0;
}
