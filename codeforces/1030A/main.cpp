#include <bits/stdc++.h>


using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t n; cin >> n;
  bool flag = false;
  for(size_t i = 0; i < n; ++i) {
    int x; cin >> x;
    if(x == 1) flag = true;
  }

  cout << (flag ? "HARD": "EASY") << '\n';
   

  return 0;
}
