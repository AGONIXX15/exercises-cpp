#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;

    vector<int> subtasks(n);
    for(auto& val: subtasks) cin >> val;

    if(find(subtasks.begin(),subtasks.end(),100) != subtasks.end()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
