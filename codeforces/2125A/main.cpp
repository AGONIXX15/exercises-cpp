#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    string s; cin >> s;



    if(s.find("FFT") == string::npos && s.find("NTT") == string::npos) {
      cout << s << '\n';
      continue;
    }


    
    unordered_map<char,int> dct;

    for(auto& val: s) dct[val]++;
    string ans;
    
    while(dct.count('T') && dct['T'] > 0) {
      ans.push_back('T');
      dct['T']--;
    }

    
    for(auto& pair: dct) {
      while(pair.second > 0) {
        ans.push_back(pair.first);
        pair.second--;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
