#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n, m;
    cin >> n >> m;
    int max_value = 0;
    int cnt_max = 0;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> matrix[i][j];
        if (matrix[i][j] > max_value) {
          max_value = matrix[i][j];
          cnt_max = 1;
        } else if (max_value == matrix[i][j]) cnt_max++;
      }
    }

    vector<int> r(n), c(m);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(matrix[i][j] == max_value) {
          ++r[i];
          ++c[j];
        }
      }
    }

    bool flag = false;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(r[i] + c[j] - (matrix[i][j] == max_value) == cnt_max) {
          flag = true;
        }
      }
    }

    cout << max_value - flag << '\n';

  }
}
