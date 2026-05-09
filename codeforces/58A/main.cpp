#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  
  //0 visited nothing
  //1 visited h
  //2 visited e
  //3 visited l
  //4 visited second l
  //5 visited o finish all good
  //
  unordered_map<int, unordered_map<char,int>> states = {
  {0,{{'h',1}}},
  {1,{{'e',2}}},
  {2,{{'l',3}}},
  {3,{{'l',4}}},
  {4,{{'o',5}}}
  };

  string s; cin >> s;
  int state = 0;
  
  for(auto c: s) {
    state = (states[state].count(c)) ? states[state][c]: state;
  }

  if(state == 5) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
