#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

int knapsack(vector<int> values, vector<int> weights, int space) {
  int n = values.size();
  vector<vector<int>> dp(n + 1, vector<int>(space + 1, 0));
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < space + 1; ++j) {
      if (weights[i - 1] <= j) {
        dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - weights[i-1]] + values[i-1]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][space];
}

int main() {
  cout << knapsack({8,9,0,5}, {1,2,3,2},4) << endl;
  return 0;
}
