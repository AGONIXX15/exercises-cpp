#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t n, k;
  cin >> n >> k;
  bool flag = false;
  size_t total = 0;
  size_t index = 0;
  size_t k_value = 0;
  while(index < k) {
    size_t x; cin >> x;
    k_value = x;
    if(x != 0) ++total;
    ++index;
  }
  while(index < n) {
    size_t x; cin >> x;
    if(x != 0 && x == k_value){
      ++total;
    }
    ++index;
  }

  cout << total << '\n';

  return 0;
}
