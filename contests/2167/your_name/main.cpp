#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;

    
    unordered_map<char,int> dct1,dct2; 
    string s1,s2; cin >> s1 >> s2;
    for(auto c: s1) {
      dct1[c]++;
    }

    for(auto c: s2) {
      dct2[c]++;
    }

      
    
    bool flag = true;
    for(auto c: s2) {
      if(dct1[c] != dct2[c]) {
        flag = false;
        break;
      }
    }

    if(flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }



  }

  return 0;
}
