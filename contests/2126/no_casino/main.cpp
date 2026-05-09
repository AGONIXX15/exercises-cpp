#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    int count = 0;
    int value = 0;
    bool jump = false;
    for(int i = 0; i < n; ++i) {
      int x; cin >> x;
      if(jump) {
        jump = !jump;
        continue;
      }

      if(x == 1) {
        count = 0;
        continue;
      } else {
        count++;
      }

      if (count == k) {
        value++;
        count = 0;
        jump = true;
        continue;
      }

    
    }

    cout << value << '\n';
  }
  return 0;
}
