#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// factorial(n) = n*factorial(n-1);

// factorial(costo) = resultado
vector<ll> dp(60,-1);
ll factorial(ll n) {
  if(dp[n] != -1) return dp[n];
  
  cout << "mira los pasos que hago" << endl;
  dp[n] = n*factorial(n-1);
  return dp[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  dp[0] = 1;
  // int n; cin >> n;
 cout << "resultado: " <<  factorial(5) << endl;
 cout << "resultado: " <<  factorial(6) << endl;
 cout << "resultado: " << factorial(8) << endl;

  
  return 0;
}
