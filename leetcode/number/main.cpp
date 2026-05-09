#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int number; cin >> number;


  int res = 0;
  while(number != 0) {
    int digit = number % 10;
    number /= 10;
    if(digit == 0) continue;
    res = res * 10 + digit;
  }

  cout << res << '\n';
  return 0;
}
