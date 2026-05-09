#include <bits/stdc++.h>

using namespace std;

int price(long long n) {
  if(n <= -1) return 0;

  return pow(3,n+1) + n*pow(3,n-1);
}

int sol(long long n) {

  if(n < 3 && n >= 0) {
    return n * 3;
  } else if(n < 0) {
    return 0;
  }
  
  long long x =  floor(logf(n)/log(3));
  long long value = price(x);
  return  value + sol(n - pow(3,x));
}



int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    // 3^x <= y
    //  x <= log3 y
    size_t n; cin >> n;
    cout << sol(n) << '\n';
  }
  return 0;
}
