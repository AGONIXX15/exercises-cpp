#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int n; cin >> n;
  int sum = 0;
  while(n--) {
    int a,b,c; cin >> a >> b >> c;
    if(a + b + c > 1) sum++;
  }
  cout << sum << '\n';
  return 0;
}
