#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int max_sum = 0;
    int index = 1;
    for(int i = n;  i > 0; --i){
      max_sum += abs(i - index);
      ++index;
    }
    cout << max_sum / 2 + 1 << '\n';
  }
}
