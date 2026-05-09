#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  unordered_set<char> uset = {'a','e','i','o','u', 'A','E', 'I', 'O', 'U','y','Y'};
  string s; cin >> s;
  string n;
  for(int i = 0; i < s.size(); ++i) {
    if(uset.find(s[i]) != uset.end()) {
      continue;
    } 
    
    if( s[i] >= 'A' && s[i] <= 'Z') {
      char c = (char)((int)s[i] + 32);
      n.append(".");
      n.push_back(c);
    } else {
      n.push_back('.');
      n.push_back(s[i]);
    }
  }

  cout << n << '\n';
  return 0;
}
