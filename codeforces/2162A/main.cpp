#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int l = 0, r = 0;

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    int max_element = 0;
    for(size_t i = 0; i < n; ++i) {
      int x; cin >> x;
      max_element = max(max_element,x);
    }

    cout << max_element << '\n';
  }

  return 0;
}
