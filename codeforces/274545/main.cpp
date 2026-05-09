#include <bits/stdc++.h>

using namespace std;

class BitTree {
  size_t n;
  vector<long long> bits;
public:
  BitTree(size_t n):n(n), bits(n+1,0){}
  

};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t n; cin >> n;
  // number, index
  pair<long long,size_t> current_max(0,0);
  
  for(size_t i = 1; i <= n; ++i) {

    size_t x; cin >> x;

    if(current_max.first > x) {
      cout << current_max.second << ' ';
    } else {
      current_max.first = x;
      current_max.second = i;
      cout << 0 << ' ';
    }


  }
  cout << '\n';
  

  return 0;
}
