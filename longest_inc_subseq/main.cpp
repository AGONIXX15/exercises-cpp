#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  // [1,2,3,4,5] # 5
  // [-1, -2 -10 1 2 3] # 4

  vector<int> v{-1,-2,-10,1,2,3};

  vector<int> dp(v.size(),1);
  
  int maximum = 0;
  for(int i = v.size()-1; i >= 0; --i) {
    for(int j = i+1; j < v.size(); ++j) {
      if(v[j] > v[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
        maximum = max(maximum, dp[i]);
      }
    }
  }

  cout << dp[0] << '\n';

  return 0;

  
}
