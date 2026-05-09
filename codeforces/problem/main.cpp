#include <bits/stdc++.h>


using namespace std;


void helper(vector<pair<int,int>>& v, int n, int start = 0) {

}

bool brute_force(vector<pair<int,int>>& v, int n, int value = 0, int start = 0) {
  if(start >= v.size()) return false;
  if(value > n) return false;
  if(value == n) return true;

  if(v[start].second > 0) {
    v
    return brute_force(v,n,value + v[start].first, start) ||  
    brute_force(v,n,value,start+1);
  }
  return brute_force(v,n,value,start+1);
}

int main() {

  vector<pair<int,int>> v = {
    {100,40},
    {200,30},
    {500,15},
    {1000,10}
        
  };
  int n = 4000;
  cout << brute_force(v,n) << '\n';
  return 0;
}
