#include <bits/stdc++.h>

using namespace std;

int helper(vector<int>& v,int pos,int sum, int trys, int n) {
  if(sum == n) {
    return trys;
  }
  if (sum > n || pos >= v.size()) return 1e9;
  
  return min(helper(v,pos+1,sum+v[pos],trys+1,n), helper(v,pos+1,sum,trys,n));
}

int func(vector<int>& v, int n) {
  
  return helper(v,0,0,0,n);
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  vector<int> v = {1,2,4,8};
  size_t n; cin >> n;
  cout << func(v,n) << '\n';
}

