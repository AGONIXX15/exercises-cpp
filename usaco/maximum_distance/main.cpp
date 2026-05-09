#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<pair<int,int>> v(n);

  for(auto& p: v) {
    cin >> p.first;
  }
  for(auto& p: v) {
    cin >> p.second;
  }

  int max_distance = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      int dx = v[j].first - v[i].first;
      int dy = v[j].second - v[i].second;
      int square = dx * dx + dy * dy;
      max_distance = max(max_distance, square);
    }
  }
  cout << max_distance << '\n';

  return 0;
}
