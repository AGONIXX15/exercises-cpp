#include <bits/stdc++.h>

using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for(auto& var: v) {
    os << var << " ";
  }
  return os;
}
#define LIMIT 120'000

using ll = long long;
vector<bool> is_prime(LIMIT+1, true);
vector<ll> siege(int n) {
  is_prime[0] = is_prime[1] = false;
  vector<ll> primes;
  for(ll i = 2; i <= n; ++i) {
    if(is_prime[i]) {
      primes.push_back(i);
      for(ll j = i*i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  vector<ll> primes = siege(LIMIT);
  // cout << "primes: "<< primes.size() << '\n';

  while(t--) {
    
    int n; cin >> n;
    for(ll i = 1; i <= n; ++i) {
      cout << primes[i] * primes[i-1] << " ";
    }
    cout << '\n';
  }


  return 0;
}
