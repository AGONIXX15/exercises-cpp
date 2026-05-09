#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    size_t k; cin >> k;
    string str; cin >> str;
    size_t sub = 0;
    // states
    // 0 no subsequence
    // 1 subarray of zero
    
    for(size_t i = 0; i < str.size(); ++i) {
      
      if(str[i] == '1') 
        ++sub;

    }
    cout << ((sub <= k || n < 2*k) ? "alice": "bob" ) <<'\n';
  }
}
