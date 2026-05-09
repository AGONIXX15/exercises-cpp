#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n;
  cin >> n;
  size_t m;
  cin >> m;
  priority_queue<int, vector<int>, greater<int>> pq;
  while (n--) {
    int number; std::cin >> number;
    pq.emplace(number);
  }
  
  int curr_sum = 0;
  int max_sum = 0;
  
  while(m--){
    curr_sum = min(curr_sum, curr_sum + pq.top());
    max_sum = min(max_sum, curr_sum);
    pq.pop();
  }

  cout << -max_sum << endl;
}
