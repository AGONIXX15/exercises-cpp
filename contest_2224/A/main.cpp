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
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    ll n; cin >> n;
    vector<ll> v(n);
    for(auto& val: v) cin >> val;
    int count = 0;
    for(int i = n-2; i >= 0; --i) {
      if(v[i] > 0) {
        if(v[i+1] > 0) v[i] += v[i+1];
        count++;
        continue;
      }
      else if(v[i] +v[i+1] > 0) {
        v[i] += v[i+1];
        count++;
      }
    }
    
    if(v[n-1] > 0) count++;
    cout << count << '\n';
  }
  return 0;
}
