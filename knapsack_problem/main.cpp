#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t items, capacity;
  cin >> items >> capacity;
  vector<int> things(items), weight(items);
  for (size_t i = 0; i < items; ++i) {
    cin >> weight[i];
    cin >> things[i];
  }
  const int INF = 1e9;
  vector<vector<int>> v(items + 1, vector<int>(capacity + 1, 0));
  for (size_t i = 0; i < items; ++i)
    v[i][0] = 0;

  for (size_t i = 0; i < capacity; ++i)
    v[0][i] = 0;

  for (size_t i = 1; i <= items; ++i) {

    for (size_t j = 1; j <= capacity; ++j) {
        
      if(weight[i-1] <= j) {
        v[i][j] = max(v[i-1][j], v[i-1][j - weight[i-1]] + things[i-1]);
      } else {
        v[i][j] = v[i-1][j];
      }
    }
  }
  cout << v[items][capacity] << '\n';

  return 0;
}
