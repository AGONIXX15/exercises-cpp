#include <bits/stdc++.h>

using namespace std;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0); 
  string s = "{()[]}";
  vector<char> v;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '{' ) v.push_back('}');
    else if(s[i] == '(') v.push_back(')');
    else if(s[i] == '[') v.push_back(']');
    else {
      if(v.size() > 0 && v.back() == s[i]) v.pop_back();
      else {
        cout << "not valid\n";
        return 1;
      }
    }

  }

  cout << "valid" << '\n';
  return 0;
}
