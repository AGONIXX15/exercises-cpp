#include <bits/stdc++.h>

using namespace std;

size_t changes(vector<vector<int>>& matrix) {
      int n = matrix.size();
  
  // recorrer solo la cuarta parte
  size_t op = 0;
  for(int i = 0; i < (n+1)/2; ++i) {
    // antes de la mitad para no contar duplicados
    for(int j = 0; j < n/2; ++j) {
      size_t a = matrix[i][j];
      // 90
      size_t b = matrix[n-j-1][i];
      // 180
      size_t c = matrix[n-i-1][n-j-1];
      // 270
      size_t d = matrix[j][n-i-1];

      size_t total = a + b + c + d;
      op += min(total, 4 - total);
    }

  }
  return op;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      string row; cin >> row;
      for (int j = 0; j < n; ++j) {
        matrix[i][j] = row[j] - '0';
      }
    }

    size_t op = changes(matrix);

    cout << op << '\n';
  }
}
