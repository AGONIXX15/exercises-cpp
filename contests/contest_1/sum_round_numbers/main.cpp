#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t;
  cin >> t;
  while (t--) {
    string x;
    cin >> x;
    vector<int> v;
    for(int i = 0; i < x.size(); ++i) {
    int value = ((x[i] - '0')*pow(10,x.size()-i-1));
    if(value != 0) v.push_back(value);
  }
    
    cout << v.size() << '\n';
    for(auto val: v) {
      if(val == 0) break;
      cout << val << " ";
    }
    cout << '\n';

  }
  return 0;
}
