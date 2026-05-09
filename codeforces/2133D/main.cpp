#include <bits/stdc++.h>

using namespace std;

void apply_operation(size_t index, vector<size_t>& v) {
  int accumulate_damage = v.size()-1 - index;
    v[index] = 0;
  
  if(index + 1 < v.size()) {
    v[index+1] -= accumulate_damage;
    if(v[index+1] <= 0) apply_operation(index+1,v);
  }
}

template <typename T>
ostream& operator<<(ostream& os, const std::vector<T>& v) {
  for(const auto& val: v) {
    os << val << " ";
  }
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  cout << "starting test:" << '\n';
  while(t--) {
    size_t n; cin >> n;
    vector<size_t> v(n);
    // the key is to choose always the minimum one that makes more damage
    for(auto& val: v) cin >> val;

    cout << v << '\n';
    size_t steps = 0;
    // index, cost
    for(size_t i = 0; i < n; ++i) {
      size_t cost = v[i];
      size_t accumulate_damage = v.size()-1-i;
      std::pair<size_t,size_t> p;
    }
  }
  return 0;
}
