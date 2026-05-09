#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n,m; cin >> n >> m;

    long long actual_min = 0;
    bool position = false;
    long long points = 0;
    for(long long i = 0; i < n; ++i) {
      long long a; cin >> a;
      bool b; cin >> b;

      // steps = a - actual_min
      // 2*l = steps
      // points = floor(steps/2)
      // else 
      // if(steps % 2 == 1) {
      //  points += steps else steps - 1
      // }

      long long steps = a - actual_min;
      if(position == b) {
        points += steps/2;
      } else {
        points += (steps % 2 == 1) ? steps : steps - 1;
        position = !position;
      }

      actual_min = a;
    }

    points += m - actual_min;
    cout << points << '\n';
    
  }

  return 0;
}
