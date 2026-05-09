#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

  size_t n;
  cin >> n;
  while (n--) {
    size_t d, t;
    cin >> d >> t;
    // find the first 1
    
    size_t curr_index = 0;
    for(size_t i = 0; i < d; ++i) {
      curr_index = i;
      char number; cin >> number;
      if(number == '1') break;
    }
    bool flag = true;
    for(size_t i = curr_index+1; i < d; ++i){
      char number; cin >> number;
      if(number == '1' && i - curr_index >= t) {
        flag = false;
      }
    }

    cout << ((flag) ? "YES": "NO") << '\n';
  }
}
