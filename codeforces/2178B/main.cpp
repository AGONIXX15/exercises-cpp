#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for(auto& val: v) {
    os << val << ' ';
  }
  return os;
}
template <typename T, typename K>
ostream& operator<<(ostream& os, unordered_map<T,K>& v) {
  for(auto& val: v) {
    os << val.first << ": " << val.second <<  '\n';
  }
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    
    string s; cin >> s;
    int n = s.size();
    int count = 0;
    if(s[0] == 'u') {
      count++;
      s[0] = 's';
    }
    if(s[n-1] == 'u') {
      count++;
      s[n-1] = 's';
    }
    for(int i = 1; i < n; ++i) {
      if(s[i] == 'u' && s[i] == s[i-1]) {
        s[i] = 's';
        count++;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
