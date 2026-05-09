#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout, std::endl, std::vector;

struct pair_hash {
  std::size_t operator()(const std::pair<int, int> &p) const noexcept {
    std::size_t h1 = std::hash<int>{}(p.first);
    std::size_t h2 = std::hash<int>{}(p.second);
    return h1 ^ (h2 << 1);
  }
};

int sum(vector<int> &nums, int index, int curr_sum, int target,
        std::unordered_map<std::pair<int, int>, int, pair_hash> &dp) {
  if (curr_sum > target || index >= nums.size()) {
    return 0;
  }
  if (curr_sum == target) {
    return 1;
  }

  if (dp.count(std::make_pair(index, curr_sum)) != 0) {
    return dp[std::make_pair(index, curr_sum)];
  }

  dp[std::make_pair(index, curr_sum)] =
      sum(nums, index, curr_sum + nums[index], target, dp) +
      sum(nums, index + 1, curr_sum, target, dp);
  return dp[std::make_pair(index, curr_sum)];
}

int combination_sum4(vector<int> &nums, int target) {
  std::unordered_map<std::pair<int, int>, int, pair_hash> dp;
  return sum(nums, 0, 0, target, dp);
}


int main() {
  vector<int> res = {1, 2, 3};
  cout << combination_sum4(res, 4) << endl;
  return 0;
}
