#include <bits/stdc++.h>

using namespace std;

// int helper(vector<int>& v, int pos, int coins) {
//   if(pos-1 >= v.size()) {
//     return coins;
//   }
//   return max(helper(v, pos*2, coins + v[pos-1]), helper(v, pos*2+1, coins + v[pos-1]));
// }
// int func(vector<int>& v) {
//   return helper(v,1,0);
// }

// template <typename T>
// void print_vector(vector<T>& vec) {
//   for (auto v: vec) {
//     cout << v << ' ';
//   }
//   cout << '\n';
// }



int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n; cin >> n;

  int size = pow(2,n) -1;
  vector<int> v(size+1);
  for(int i = 1; i <= size; ++i) {
    int value; cin >> value;
    v[i] = value;
  }
  // we need to improve the solution, need to change it to dp cause it was in brute force
  // dp(i) = v[i] if 2 * i + 1 > size else v[i] + max(dp[2*i], dp[2*i+1]);

  vector<int> dp(size+1);
  for(int i = size; i >= 1; --i) {
    if(2*i+1 > size){
      dp[i] = v[i];
    } else {
      dp[i] = v[i] + max(dp[2*i], dp[2*i+1]);
    }
  }

  cout << dp[1] << '\n';
  return 0;
}


