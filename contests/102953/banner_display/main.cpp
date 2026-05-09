#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
  string s = "coderams";
  unordered_map<char,int> dct;
  size_t n; cin >> n;
  string s1; cin >> s1;

  for(auto character: s1) {
    dct[character]++;
  }

  int minimun = 1e9;
  for(auto character: s){
    minimun = min(minimun, dct[character]);
  }
  cout << minimun << '\n';
  return 0;
}
