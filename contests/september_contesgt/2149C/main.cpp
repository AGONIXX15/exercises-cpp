#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n,k; cin >> n >> k;

    unordered_set<long long> v(n);

    long long many_k = 0;
    for(size_t i = 0; i < n; ++i) {
      long long val; cin >> val;
      if(val == k) many_k++;
      v.insert(val);
    }
  

    
    long long minimum = 0;
    long long copy_many_k = many_k;
    for(size_t i = 0; i < k; ++i) {

      if(!v.count(i) && copy_many_k > 0) {
        copy_many_k--;
      } else if(!v.count(i)) {
        minimum++;
      }
    }

    if(v.count(k)) minimum += many_k;

    cout << minimum << '\n';

  }
  return 0;
}
