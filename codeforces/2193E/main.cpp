#include <bits/stdc++.h>

using namespace std;

void obtain_divisor(int n, vector<long long>& divisors) {

  int limit = sqrt(n);
  for(int i = 1; i <= limit; ++i) {
    
    if(n % i == 0) {
      divisors.push_back(i);
      if(i == n / i) continue;
      divisors.push_back(n / i);
    }
  }
}

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << "[";
  for(size_t i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "" : ", ");
  }
  os << "]";
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  // vector<int> divisors;
  // int n = 50;
  // obtain_divisor(n, divisors);
  // cout << divisors << '\n';


  size_t t; cin >> t;
  while(t--) {
    
    size_t n; cin >> n;
    vector<long long> v(n);
    for(auto& val: v) cin >> val;
    vector<vector<long long>> divisors;
    for(size_t i = 1; i <= n; ++i) {
      obtain_divisor(i, divisors[i-1]);
    }
    
    
    vector<long long> dp(n, 1e9);
      for (int x = 1; x <= n; ++x) {
        for (int y : divisors[x]) {
            int z = x / y;
            if (z <= n) {
                dp[x] = min(dp[x], dp[y] + dp[z]);
            }
        }
    }


    for(auto& val: dp) if(val == 1e9) val = -1;

    cout << dp << '\n';
  }

}
