#include <bits/stdc++.h>

using namespace std;

size_t binary_search_cost(size_t n, size_t b, size_t secret_cost) {

  size_t l = 1, r = n;
  size_t cost = 0;
  while (l <= r) {
    size_t mid = (l + r) / 2;

    if (mid == secret_cost) {
      cost += mid;
      break;
    } else {
    cost += b;

      if (mid < secret_cost) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }

  cout << "secret_cost:" << secret_cost << " cost:" << cost << '\n';
  return cost;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n, b;
  cin >> n >> b;

  size_t max_cost = 0;

  for (size_t i = 1; i <= n; ++i) {
    max_cost = max(max_cost, binary_search_cost(n, b, i));
  }
  cout << max_cost << '\n';

  return 0;
}
