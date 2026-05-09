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


int dp[10'000];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> v(n);
    for(auto& val: v) cin >> val;
    
    bool flag = false;
    for(int i = 0; i < n; ++i) {
      int a = v[i];
      int b = 0;
      for(int j = 0;  j < n; ++j) {
        if(i == j) continue;

        if(b == 0) b = v[j];
        else if(b != 0) {
          b = gcd(b,v[j]);
        }
      }
      if(a != b) {
        flag = true;
        cout << "Yes\n";
        for(int k = 0; k < n; ++k){
          if(k == i) cout << "1 ";
          else cout << "2 ";
        }
        cout << '\n';
        break;
      }
    }
    if(!flag) cout << "No\n";
  }

  return 0;
}
