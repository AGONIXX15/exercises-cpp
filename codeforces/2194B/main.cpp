#include <bits/stdc++.h>


using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << '[';
  for(size_t i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "" : ", ");
  }
  os << ']';
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n,x,y; cin >> n >> x >> y;

    vector<size_t> v(n);
    for(auto& val: v) cin >> val;

    cout << v << '\n';
    // x + y <= v[i]
    // z = x + y
    // steps = v[i] / z

    int sum = v[0];
    for(size_t i = 1; i < v.size(); ++i) {
      int steps = v[i] / x;
      sum += y * steps;
    }
    
    cout << sum << '\n';
  }
}
