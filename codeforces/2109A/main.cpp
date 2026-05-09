#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  unordered_map<int,unordered_map<int,int>> states = {
    {0, {{1,1}, {0,2}}},
    {1, {{1,5}, {0,2}}},
    {2, {{1,3}, {0,4}}},
    {3, {{1,3}, {0,2}}},
    {4,{{1,4},{0,4}}},
    {5,{{1,5}, {0,2}}},
  };
  while(t--) {
    size_t n; cin >> n;
    size_t state = 0;
    for(int i = 0; i < n; ++i) {
      size_t input; cin >> input;
      state = states[state][input];
    }

    if(state == 4 || state == 5) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
