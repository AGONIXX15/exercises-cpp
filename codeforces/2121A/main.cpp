#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {

    size_t n, s;
    cin >> n >> s;

    if (n == 1) {
      int x;
      cin >> x;
      cout << abs(x - (int)s) << '\n';
      continue;
    }

    int min_element = 1e5, max_element = -1e5;
    for (size_t i = 0; i < n; ++i) {
      int x;
      cin >> x;
      min_element = min(min_element, x);
      max_element = max(x, max_element);
    }
    
    int result = min(abs(max_element-(int)s), abs(min_element-(int)s)) + (max_element-min_element);
    cout << result << '\n';
  }

  return 0;
}
