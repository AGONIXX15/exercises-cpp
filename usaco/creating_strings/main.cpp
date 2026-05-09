#include <bits/stdc++.h>


using namespace std;

void permute(unordered_map<char,int>& dct, string& ans,vector<string>& res, int length) {
  if(ans.size() == length) {
    res.push_back(ans);
    return;
  }
  
  for(auto& pair: dct) {
    if(pair.second > 0) {
      pair.second--;
      ans.push_back(pair.first);
      permute(dct, ans, res,length);
      ans.pop_back();
      pair.second++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  string s; cin >> s;
  string ans; 
  vector<string> res;
  unordered_map<char,int> dct;
  for(auto val: s)  dct[val]++;
  permute(dct,ans, res,s.size());
  cout << res.size() << '\n';
  for(auto& str: res) cout << str << '\n';

  return 0;
}
