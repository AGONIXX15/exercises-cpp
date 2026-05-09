#include <bits/stdc++.h>

using namespace std;

int main() {

  int t = 1;
  // cin >> t;
  while (t--) {
    int n = 7;
    // cin >> 
    vector<long long> v = {2,6};
    for (size_t i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    vector<long long> prefix(n + 1);
    for (int i = 1; i < n + 1; ++i) {
      prefix[i] = prefix[i - 1] + v[i-1];
    }

    for (int i = 1; i <= n; ++i) {
      cout << prefix[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
