#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

int longest_subsequence(vector<int>& arr){
  int n = arr.size();
  vector<int> dp(n, 1);
  int ans = 0;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < i; ++j){
      if(arr[j] < arr[i]){
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    ans = std::max(ans, dp[i]);
  }
  return ans;
}

int main() {

  vector<int> q = {1,3,5,2, 10,10, 20};
  cout << longest_subsequence(q ) << endl;
  return 0;
}
