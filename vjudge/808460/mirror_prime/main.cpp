#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
  if(n == 2) return true;
  else if(n < 2) return false;

  for(int i = 2; i*i <= n; ++i) {
    if(n % i == 0) return false;
  }
  return true;
}
int reverse_number(int n) {
  int res = 0;
  while(n) {
    res = res * 10 + (n % 10);
    n /= 10;
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int a,b; cin >> a >> b;

  int count = 0;
  for(int i = a; i <= b; ++i) {
    // cout << i << " reverse i: " << reverse_number(i) << '\n';
    if(is_prime(i) && is_prime(reverse_number(i)))  count++;
  }
  cout << count << '\n';

  return 0;
}
