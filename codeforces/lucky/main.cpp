#include <bits/stdc++.h>

using namespace std;

bool brute_force(int curr, int n, int height) {
  if(height > 3) return false;
  if(curr != 0 && n % curr == 0) return true;
  return brute_force(curr*10 + 4,n, height+1) || 
  brute_force(curr*10 + 7, n,height+1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n; cin >> n;

  cout << (brute_force(0,n,0) ? "YES":"NO") << '\n';
  
  return 0;
}
