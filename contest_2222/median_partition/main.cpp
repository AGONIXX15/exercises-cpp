#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(5000,vector<int>(2,-1));

int f(int i,int& val,int lesser, int greater, int count,bool state, vector<int>& v) {
  if(i >= v.size()) return 0;
  int& ans = dp[i][state];
  if(ans != -1) return ans;

    if(v[i] > val) greater++;
    else if(v[i] < val) lesser++;
    else count++;
  // cout << "lesser: " << lesser << ' ';
  // cout << "greater: " << greater <<' ';
  // cout << "count: " << count << '\n';
  if((greater + lesser + count) & 1 && abs(greater - lesser)  < count) {

    int p = f(i+1,val,0,0,0,true,v);
    if(p != 0 || i+1 == v.size()) ans = p+1;
    // greater = lesser = count = 0;
  }

  ans = max(f(i+1,val,lesser,greater,count,false,v),ans);
  return ans;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    unordered_set<int> st;
    vector<int> v(n);
    for(auto& val: v){  
      cin >> val;
      st.insert(val);
    }
    
    int result = 1;
    for(auto val: st) {
      for(int i = 0; i < n; ++i) {
        dp[i][0] = -1;
        dp[i][1] = -1;
      }
      // cout << "val: " << val << '\n';
      result = max(result, f(0,val,0,0,0,false,v));
      // cout << "\n\n";
    }
    cout << result << '\n';
  }
  return 0;
}
