#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    char s[n];
    for(auto& c: s) cin >> s;
    cout << s << '\n';
    

    int count = 0;
    for(size_t i = 1; i < n-1; ++i) {
      cout << "index: " <<  i << '\n';
      if(( i-1 >= 0 && s[i-1] == '0') && s[i] == '0' && (i+1 < n && s[i+1] == '0')) {
        count++;
        s[i-1] = '1';
        s[i] = '1';
        s[i+1] = '1';
      }
    }
    // cout << s << '\n';
    // cout << "count: " << count << '\n';

    for(size_t i = 0; i < n; ++i) {


      if(i-1 >= 0 && s[i-1] == '0' && s[i] == '0') {
        s[i-1] = '1';
        s[i] = '1';
        count++;
      } 
      else if(i+1 < n && s[i+1] == '0' && s[i] == '0') {
        s[i+1] = '1';
        s[i] = '1';
        count++;
      } 
      else {
        s[i] = '1';
        count++;
      }
    }

    cout << count << '\n';
  }
  return 0;
}
