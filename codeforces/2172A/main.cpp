#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  vector<int> v(3);
  int minimum = 1e9, maximum = -1e9;
  for(auto& val: v) {
    cin >> val;
    minimum = min(minimum,val);
    maximum = max(maximum,val);
  }


  sort(v.begin(),v.end());
  if(maximum - minimum >= 10) {
    cout << "check again\n";
  } else cout << "final " << v[1] << '\n';

  return 0;
}
