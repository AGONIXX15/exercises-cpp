#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n; cin >> n;
  while(n--) {
    // a or b valid this condition has to be for both
    // a*3 >= b

    int a,b,c,d; cin >> a >> b >> c >> d;
    
    int x = c - a;
    int y = d - b;
    if(max(a,b) > 2*min(a,b)+2) {
      cout << "NO" << '\n';
    } else if(max(x,y) > 2 *min(x,y)+2) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }

  }

  return 0;
}
