#include <bits/stdc++.h>


using namespace std;

int n;
int COUNT;
void search(int y,vector<int>& column, vector<int>& diag1, vector<int>& diag2) {
  if(y == n) {
    COUNT++;
    return;
  }
  for(int x = 0; x < n; ++x) {
    if(column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
    column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
    search(y+1, column, diag1, diag2);
    column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  vector<int> column(n,0);
  vector<int> diag1(2*n-1, 0);
  vector<int> diag2(2*n-1, 0);
  search(0, column, diag1, diag2);
  cout << COUNT << '\n';

  return 0;
}
