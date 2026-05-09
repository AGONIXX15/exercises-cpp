#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n, m;
  cin >> n >> m;

  bool end = true;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      if (i % 2 == 0 || (!end && j == 0) || (end && j == m - 1)) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << '\n';
    if(i % 2 == 1) end = !end;
  }
  cout << '\n';

  return 0;
}
