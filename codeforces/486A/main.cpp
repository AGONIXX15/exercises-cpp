#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);


  size_t n; cin >> n;


  if(n % 2 == 0) {
    cout << n / 2 << '\n';
  } else {
    cout << -static_cast<long long>(ceil(n * 1.0/2.0))  << '\n';
  }

  return 0;
}
