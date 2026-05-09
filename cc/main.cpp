#include <bits/stdc++.h>

using namespace std;



void helper(vector<vector<int>>& sol,vector<int>& v, int m, int start, int curr_sum) {
  if(curr_sum == m) sol.push_back(v);
  if(curr_sum > m) return;

  for(int i = start; i <= m; ++i) {
    v.push_back(i);
    cout << "i: " << i << '\n';
    helper(sol,v,m,i+1,curr_sum+i);
    v.pop_back();
  }
}

vector<vector<int>> agrupacion(int m, int start=1) {

  vector<vector<int>> sol;
  vector<int> v;

  helper(sol,v,m,start,0);
  return sol;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
  for(auto& vec: v) {
    for(auto val: vec) {
      os << val << " ";
    }
    os << '\n';
  }
  return os;
}


int main() {


  cout << agrupacion(6) << '\n';



  return 0;
}
