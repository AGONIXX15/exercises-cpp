#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  
  vector<int> v(4);
  for(auto& val: v) cin >> val;
  size_t d; cin >> d;

  size_t counter = 0;
  // time O(d), memory(1)
  for(size_t i = 1; i < d; ++i) {
    
    bool flag = true;
    for(auto& val: v)  {
      if(i % val == 0) {
        flag = false;
      }
    }
    
    if(!flag) counter++;
  }
  cout << counter << '\n';

  return 0;
}
