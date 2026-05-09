#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  string s; cin >> s;
  unordered_set<char> hashset;
  for(auto letter: s) {
    hashset.insert(letter);
  }
  
  cout << ((hashset.size() % 2 == 0) ? "CHAT WITH HER!": "IGNORE HIM!") << '\n';
  return 0;
}
