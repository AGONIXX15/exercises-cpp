#include <bits/stdc++.h>

using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)  {
  for(auto val: v) {
    cout << val << " ";
  }
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    vector<long long> v(n);
    bool even = false,odd = false;
    for(auto& val: v) {
      cin >> val;
      if(val % 2 == 0) {
        even = true;
      } else {
        odd = true;
      }
    }


    if(even && odd) {
      sort(v.begin(),v.end());
    }
    cout << v << '\n';
    

  }

  return 0;
}
