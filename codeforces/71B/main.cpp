#include <bits/stdc++.h>

using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n,k,t; cin >> n >> k >> t;
  // n * k panes totales
  // (n * k) t/100
  double result =  n * k * t/100.0;
  for(int i = 0; i < n; ++i) {
    int progress = min(result, static_cast<double>(k));
    cout << progress << ' ';
    result -= progress;
  }
  cout << '\n';
  
  return 0;
}
