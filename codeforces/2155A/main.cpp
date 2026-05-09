#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  // n -> 7
  // floor(n/2) + 1
  // floor(3/2) + 1
  

  size_t t; cin >> t;
  while(t--) {

    size_t n; cin >> n;
    long long total_games = 1;
    

    long long winners = (n % 2 == 0) ? n/2: n/2 + 1;
    long long losers_games = (winners % 2 == 0 || winners == 1) ? winners/2: winners/2 + 1;

    cout << winners + losers_games + 1 << '\n';
  }


  return 0;
}
