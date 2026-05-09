#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os,vector<T>& v) {
  os << '[';
  for(int i = 0; i <v.size(); ++i) {
    os << v[i] << (i != v.size()-1 ? ", ": "");
  }
  os << ']';
}
vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid) {
  int n = boxGrid.size(), m = boxGrid[0].size();

  for (int i = 0; i < n; ++i) {
    int count = 0;
    for (int j = 0; j < m; ++j) {
      if (boxGrid[i][j] == '#') {
        count++;
        boxGrid[i][j] = '.';
      } else if (boxGrid[i][j] == '*') {

        for (int k = 0; k < count; ++k) {
          boxGrid[i][j - k - 1] = '#';
        }
        count = 0;
      }
        if(j == m-1) {
          // cout << count << '\n';
          for (int k = 0; k < count; ++k) {
            // cout << "pintando i,j:" << i << ", " << j - k << '\n';
            boxGrid[i][j - k] = '#';
          }
        continue;
      }
    }
  }
  // vector<vector<char>> boxGridNew(m,vector<char>(n));
  // for(int i = 0; i < m; ++i) {
  //     for(int j = 0; j < n; ++j) {
  //         boxGridNew[i][j] = boxGrid[n-1-j][i];
  //     }
  // }

  for (auto &row : boxGrid) {
    //
    for (auto &val : row) {
      cout << val << " ";
    }
    cout << '\n';
  }
  // cout << '\n';
  // return boxGridNew;
  return {};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  vector<vector<char>> v = {{'#','#','*','.','*','.'},
              {'#','#','#','*','.','.'},
              {'#','#','#','.','#','.'}};
  rotateTheBox(v);
  return 0;
}
