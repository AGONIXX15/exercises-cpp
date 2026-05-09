#include <bits/stdc++.h>

using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for(auto& val: v) os << val << " ";
  return os;
}

using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    ll n; cin >> n;
    vector<ll> v(n);
    for(auto& val: v) cin >> val;
    int l = 0, r = n-1;

    int left_sum = 0, right_sum = 0;
    int pages = 0;
    while(l <= r) {
      if(left_sum <= right_sum) {
        left_sum += v[l++];
      } else right_sum += v[r--];

      if(left_sum == right_sum) {
        pages = l + (n - r - 1);
      }
    }
    cout << pages << '\n';


  }
  return 0;
}
