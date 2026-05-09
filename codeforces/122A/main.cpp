#include <bits/stdc++.h>

using namespace std;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int numbers[] = {4,7,44,47,74,77,444,477,447,777};
  int number; cin >> number;

  bool flag = false;
  for(int i = 0; i < 10; ++i) {
    if(numbers[i] <= number && number % numbers[i] == 0) {
      flag = true;
      break;
    }
  }

  cout << ((flag) ? "YES": "NO") << '\n';

  return 0;
}
