#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> v(n);
    vector<int> six_mod;
    vector<int> three_mod;
    vector<int> two_mod;
    vector<int> neither;
    for(auto& val: v) {
      cin >> val;
      if(val % 6 == 0) six_mod.push_back(val);
      else if(val % 3 == 0) three_mod.push_back(val);
      else if(val % 2 == 0) two_mod.push_back(val);
      else neither.push_back(val);
    }

    vector<int> ans;
    for(int i = 0; i < six_mod.size(); ++i) {
      ans.push_back(six_mod[i]);
    }
    for(int i = 0; i < two_mod.size(); ++i) {
      ans.push_back(two_mod[i]);
    }
    for(int i = 0; i < neither.size(); ++i) {
      ans.push_back(neither[i]);
    }
    for(int i = 0; i < three_mod.size(); ++i) {
      ans.push_back(three_mod[i]);
    }

    for(auto& val: ans) cout << val << " ";
    cout << "\n";
    
  }
  return 0;
}
