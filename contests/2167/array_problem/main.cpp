#include <bits/stdc++.h>

using namespace std;

const vector<long long> siege(int n) {
  vector<long long> primes = {2};

  long long current_value = 3;
  while(true) {
    if(primes.size() == n) break;
    
    bool flag = true;
    for(auto val: primes) {
      if(current_value % val == 0) {
        flag = false;
        break;
      }
    }

    if(flag) primes.push_back(current_value);
    ++current_value;
  }

  return primes;

  
}

const vector<long long> primes = siege(30);
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  // for(size_t i = 0; i < primes.size(); ++i) {
  //   cout << primes[i] << " ";
  // }
  // cout << '\n';

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;


    bool flag = false;
    long long value = 1e9;
    for(size_t i = 0; i < n; ++i ) {
      long long val; cin >> val;   
      for(size_t j = 0; j < primes.size(); ++j) {
        if(gcd(val,primes[j]) == 1) {
          // cout << "val: " << val << "primes[j]: " << primes[j] << '\n';
          flag = true;
          value = min(value,primes[j]);
        }
      }
    }

    if(flag) {
      cout << value << '\n';
    } else {
      cout << -1 << '\n';
    }



  }

  
  return 0;
}
