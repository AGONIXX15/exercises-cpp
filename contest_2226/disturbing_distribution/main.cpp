#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os,vector<T>& v) {
  for(auto& val: v) {
    os << val << " ";
  }
  return os;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t;
  ll m = 676767677;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v) cin >> val;

    sort(v.begin(), v.end());
    int last_value = 1;
    int cost = 1;
    int total = 0;
    int l = 0;
    while(v[l] == 1) l++;

    while(l < n) {
      last_value = v[l];
      while(l < n && v[l] == last_value) {
        cost = (cost * v[l]) % m;
        l++;
      }
      total += cost;
      cost = 1;
    }
    cout << total << '\n';
  }
  return 0;
}
