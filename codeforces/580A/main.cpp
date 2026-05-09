#include <bits/stdc++.h>

using namespace std;

// template <typename T>
// ostream& operator<<(ostream& os,const vector<T>& v)  {
//   for(auto val: v) {
//     os << val << " ";
//   }
//   return os;
// }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t n; cin >> n;
  vector<long long> v(n);
  for(auto& val: v) cin >> val;

  long long curr_maximum = 1;
  long long maximum = 1;
  for(size_t i = 0; i < n-1; ++i) {
    if(v[i] <= v[i+1]) {
      curr_maximum += 1;
      maximum = max(maximum, curr_maximum);
    } else {
      curr_maximum = 1;
    }
  }
  cout << maximum <<'\n';

  return 0;
}
