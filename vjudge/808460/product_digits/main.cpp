#include <bits/stdc++.h>

using namespace std;

vector<int> g(int n) {
  vector<int> ans;
  for(int i = 9; i >= 2; --i) {
    while(n % i == 0) {
      ans.push_back(i);
      n /= i;
    }
  }
  return n != 1 ? vector<int>(): ans;
}
vector<int> f(int n) {
  vector<int> ans;
  for(int i = 2; i <= 9; ++i) {
    while(n % i == 0) {
      ans.push_back(i);
      n /= i;
    }
  }
  
  return n != 1 ?  vector<int>() : ans;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n; cin >> n;
  auto v1 = f(n);
  auto v2 = g(n);
  if(v1.size() == 0 || v2.size() == 0) {
    cout << "-1 -1\n";
    return 0;
  }
  reverse(v1.begin(),v1.end());
  sort(v2.begin(), v2.end());
  for(auto& v: v2) cout << v << "";
  cout << " ";
  for(auto& v: v1) cout << v << "";
  cout << '\n';
  return 0;
}
