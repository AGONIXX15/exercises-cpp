#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  size_t n;
  cin >> n;
  size_t k;
  cin >> k;
  
  size_t odds = (n+1)/2;
  size_t even = n/2;
  if(k <= odds) {
    cout << k*2LL-1LL << '\n';
  } else {
    cout << (k-odds)*2LL << '\n';
  }

  
}
