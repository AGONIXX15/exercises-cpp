#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;
bool is_prime(ll n) {
  if(n < 2) return false;
  if(n == 2) return true;

  for(ll i = 2; i*i <= n; ++i) {
    if(n % i == 0) return false;
  }
  return true;
}
ll f(int i, ll curr) {
  if(i >= s.size()) {
    return is_prime(curr) ? curr: 0;
  }

  int digit = s[i] - '0';
  
  return max(f(i+1,curr * 10 + digit),f(i+1,curr));
  
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  cin >> s;
  cout << f(0,0) << '\n';
  return 0;
}
