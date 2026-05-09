#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << '[';
  for(int i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "": ", ");
  }
  os << ']';
  return os;
}

template <typename A, typename B>
ostream& operator<<(ostream& os, pair<A,B>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename K,typename T>
ostream& operator<<(ostream& os, unordered_map<K,T>& dct) {
  os << "{";
  int i = 0;
  for(auto& [key, value]: dct ) {
    os << "{" << key << ": " << value << (++i != dct.size() ? "}, ": "}");
  }
  os << "}";
  return os;
}



int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<ll> v(n);
    ll sum = 1;
    for(auto& val: v) {
      cin >> val;
      if(val != 1) sum += val;
    }
    cout << sum << '\n';
  }
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  return 0;
}
