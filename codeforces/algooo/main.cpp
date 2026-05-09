#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define LIMIT 120'000

bool is_prime(int n) {
  if(n == 2) return true;

  for(int i = 2; i <= static_cast<int>(sqrt(n)); ++i) {
    if(n % i == 0) return false;
  }
  return true;
}

vector<ll> generate_primes(int n) {
  vector<ll> primes;
  for(int i = 2; i < n; ++i) {
    if(is_prime(i)) primes.push_back(i);
  }
  return primes;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  vector<ll> primes = generate_primes(LIMIT);
  // cout << "primes: " << primes.size() << '\n';
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
      cout << primes[i] * primes[i-1] << " ";
    }
    cout << '\n';
  }
  
  return 0;
}
