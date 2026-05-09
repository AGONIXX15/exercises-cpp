#include <bits/stdc++.h>

using namespace std;

bool brute_force(vector<int>& v, int sum, int i) {
  if(i >= v.size() && sum == 0) return true;
  else if(i >= v.size()) return false;
  
 return brute_force(v,sum + v[i], i+1) || brute_force(v,sum + v[i]*-1, i+1);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int a,b; cin >> a >> b;
    vector<int> v(a+b,1);
    for(int i = a; i < v.size(); ++i) v[i] = 2;
    cout << (brute_force(v,0,0) ? "YES\n": "NO\n");
  }
  return 0;
}
