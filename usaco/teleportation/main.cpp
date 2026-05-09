#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  freopen("teleport.in","r", stdin);
  freopen("teleport.out", "w", stdout);

  int a,b,x,y; cin >> a >> b >> x >> y;

  int minimum = min(a,b);
  int maximum = max(a,b);
  int way = min(abs(minimum-maximum), abs(minimum-min(x,y)) + abs(maximum - max(x,y)));
  cout << way << '\n';
  return 0;
}
