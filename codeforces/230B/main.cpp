#include <bits/stdc++.h>

using namespace std;

using ll = long long;


template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << '[';
  for(ll i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "": ", ");
  }
  os << ']';
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n; cin >> n;
  vector<ll> v(n);
  for(auto& val: v) cin >> val;
  // cout << v << '\n';

  for(size_t i = 0; i < v.size(); ++i) {
    
    int count = 2;
    bool flag = false;
    for(size_t j = 2; j <= ceil(sqrt(v[i])); ++j) {
      if(v[i] % j == 0) {count++;
        cout << j << '\n';
      }
      if(count > 3) break;
      
    }
    if(count == 3) flag = true;

    cout << (flag ? "YES": "NO") << '\n';
  }
  return 0;
}
