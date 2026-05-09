#include <bits/stdc++.h>
#include <cwchar>

using namespace std;

typedef long long ll;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    ll n, r1,c1,r2,c2; cin >> n >> r1 >> c1 >> r2 >> c2;

    cout << max(max(c2,max(n-c2,0ll)),max(r2,max(n - r2,0ll)) ) << '\n';
    


  }

  return 0;
}
