#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << '[';
  for(ll i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "": ", ");
  }
  os << ']';
  return os;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  size_t n; cin >> n;
  vector<ll> numbers(n);
  for(auto& val: numbers) cin >> val;

  vector<vector<ll>> ans;
  for(ll mask = 0; mask < (1 << n); ++mask) {
    vector<ll> subset;
    for(ll i = 0; i < n; ++i) {
      if(mask & (1 << i)) {
        subset.push_back(numbers[i]);
      }
    }
    ans.push_back(subset);
  }

  cout << ans << '\n';
  
  return 0;
}
