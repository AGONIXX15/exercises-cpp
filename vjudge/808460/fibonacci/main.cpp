#include <bits/stdc++.h>
#include <endian.h>

using namespace std;
bool is_prime(int n) {
  if(n < 2) return false;
  if(n == 2) return true;
  for(int i = 2; i * i <= n; ++i) if(n % i == 0) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int a = 1;
  int b = 1;
  int n; cin >> n;
  vector<int> v = {2, 3, 5, 13, 89, 233, 1597, 28657, 514229, 433494437}
;
  cout << v[n-1] << '\n';
  return 0;
}
