#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t n; cin >> n;
  size_t total = 0;
  vector<size_t> v(n);
  for(size_t i = 0; i < n; ++i) {
    cin >> v[i];
    total += v[i];
  }

  size_t my_sum = 0;
  size_t steps = 0;
  sort(v.begin(), v.end());
  for(size_t i = n-1; i >= 0; --i) {
    my_sum += v[i];
    total -= v[i];
    steps++;
    if(my_sum > total) break;
  }

  cout << steps << '\n';

  return 0;
}
