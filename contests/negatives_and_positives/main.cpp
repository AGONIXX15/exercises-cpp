#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;

    vector<int> v(n);
    int negatives = 0;
    for (auto &val : v) {
      cin >> val;
      if (val < 0) {
        negatives++;
        val = -val;

      }

    }
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(),v.end());


    negatives = negatives % 2;
    // cout << "negatives: " << negatives << '\n';

    long long sum = 0;


    if(negatives == 1) {
      sum += -abs(pq.top());
      pq.pop();
    }

    while (!pq.empty()) {
      sum += abs(pq.top());
      pq.pop();
    }

    cout << sum << '\n';
  }

  return 0;
}
