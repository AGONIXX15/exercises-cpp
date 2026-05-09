#include <bits/stdc++.h>

using namespace std;

vector<int> recursive_function(int n1, int n2, int n3, vector<int>& v) {
  if(n1 == 0 && n2 == 0 && n3 == 0) return v;
  if (n1 != 0 && n1 >= n2 && n1 >= n3) {
    v.push_back(1);
    return recursive_function(n1-1,n2,n3,v);
  }
  if (n1 != 0 && n1 >= n2 && n1 >= n3) {
    v.push_back(1);
    return recursive_function(n1-1,n2,n3,v);
  }

  if (n1 != 0 && n1 >= n2 && n1 >= n3) {
    v.push_back(1);
    return recursive_function(n1-1,n2,n3,v);
  }
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    int n1,n2,n3; cin >> n1 >> n2 >> n3;
    string s;
    // 111111
  }
  return 0;
}
