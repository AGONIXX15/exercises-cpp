#include <bits/stdc++.h>

using namespace std;

template <typename T> void print_vector(vector<T> &vec) {
  ;
  for (auto v : vec) {
    cout << v << " ";
  }
}

template <typename T> void print_matrix(vector<vector<T>> &m) {
  for (auto &v : m) {
    print_vector(v);
    cout << '\n';
  }
}

template <typename T> void rotate90d(vector<vector<T>> &m) {
  size_t n = m.size();
  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j) {
      swap(m[i][j], m[n-j-1][i]);
    }
  }
}

int main() {
  vector<vector<int>> m(5, vector<int>(5, 0));
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      m[i][j] = (i + 1) * (j + 1);
    }
  }
  cout << "first" << '\n';
  print_matrix(m);
  rotate90d(m);
  cout << "second" << '\n';
  print_matrix(m);
}
