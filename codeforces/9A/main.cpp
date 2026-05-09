#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t a,b;
  cin >> a >> b;

  // casos favorables/casos posibles
  size_t max_number = max(a,b);
  size_t posibilities = abs(static_cast<int>(max_number)-6)+1;
  double value = 1.0*posibilities/6;
  // cout << "posibilities: " << posibilities << '\n';
  bool flag = false;
  for(int i = 0; i < 7; ++i) {
    for(int j = 1; j < 7; ++j) {
    if(1.*i/j == value) {
      cout << i << "/" << j << '\n';
      flag = true;
        break;
      }
    }
    if(flag) break;
  }

  return 0;
}
