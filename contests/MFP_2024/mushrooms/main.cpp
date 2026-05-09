#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  unordered_map<int, int> dct;
  int n = 4;
  int l = 0;
  for(int i = 0; i < n; ++i) {
    int x,y; cin >> x >> y;
    if(dct.count(x) == 0) {
      dct[x] = y;
    } else {
      l = (l == 0) ? abs(dct[x] - y): l * abs(dct[x] - y);
    }
  }
  cout << l << '\n';


  return 0;
}

