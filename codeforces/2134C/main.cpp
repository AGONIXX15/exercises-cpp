#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {
  for(auto& val: v) {
    os << val << " ";
  }
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n; cin >> n;

    vector<size_t> v(n);

    vector<int> sum_odd(n+1,0);
    vector<int> sum_even(n+1,0);
    
    
    for(size_t i = 0; i < v.size(); ++i) {
      cin >> v[i];
      if(i % 2 == 0) {
        sum_odd[i+1] = sum_odd[i] + v[i];
      }
    
    }


    int cost = 0;
    for(size_t i = 1; i < n; ++i) {
      for(size_t j = 0; j <= i; ++j) {
        if(j % 2 == 0) {
          // sum_odd += v[j];
        } else {
        }
      }
      
      
      cost += (sum_even >= sum_odd) ? 0: sum_odd - sum_even;
    }
    cout << cost << '\n';

  }

  return 0;
}
