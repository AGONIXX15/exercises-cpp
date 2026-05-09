#include <bits/stdc++.h>


using namespace std;

long long sum_digits(long long n) {
  long long sum = 0;
  while(n != 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {

  size_t x; cin >> x;
  
  long long l = 1;

  long long r = 1e15;
  bool flag = false;
  while(l < r) {
    
    long long mid = (r - l)/2  + l;
    // cout << "l : " << l << " r: " << r << '\n';

    long long value = mid - sum_digits(mid);

    if(value == x) {
      cout << 10 << '\n';
      flag = true;
      break;
    } else if(value < x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

    if(!flag) cout << 0 << '\n';
  }

  return 0;
}
