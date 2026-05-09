#include <bits/stdc++.h>

using namespace std;

int calculate(int n, int cows) {
  // chickens = 2
  // 2*k + cows*y = n

  int count = 0;
  for(int i = 0; i <= floor(1.0*n/4.0); ++i) {
      
    // 2*k =n - cows*y
    // k = (n - cows*y)/2
    //
    double k = 1.0 * (1.0*n - 1.0*cows*i)/2.0;
    if(k == static_cast<int>(k)) {
      
      count += 1;
    }
  }
  return count;

}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);


  size_t t; cin >> t;
  while(t--) {
    int n; cin >> n;
    cout << calculate(n,4) << '\n';
  }
  return 0;
}
