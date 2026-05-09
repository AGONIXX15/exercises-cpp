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


// memoization
// unordered_map<int,int> dp;
// int f(int n,int m, int a, int b) {
//   if(n <= 0) return 0;
//   if(dp.count(n)) return dp[n];
//   // cout << "n: " << n << " m: " << m << " a: " << a << " b: " << b << '\n';
//   int &ans = dp[n];
//   

//   ans = min(a+f(n-1,m,a,b), b+f(n-m,m,a,b));
//   return ans;
// }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n,m,a,b; cin >> n >> m >> a >> b;

  // cout << f(n,m,a,b) << '\n';
  vector<int> dp(n+1,1e7);
  dp[0] = 0;

  // cout << dp << '\n';
  // if n <= 0: return 0
  //
  // f(0,n,m,a,b) = 0
  // f(1,n,m,a,b) = min(f(0)+a,f(n-m)+b);
  for(int i = 1; i <= n; ++i) {
    dp[i] = min(dp[i-1]+a,
              dp[max(0,i-m)]+b);
  }
  // cout << dp << '\n';
  cout << dp[n] << '\n';


  return 0;
}
