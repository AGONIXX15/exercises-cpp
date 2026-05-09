#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;
    // imod2=a[i]mod2
    size_t arr[] = {0,0};
    for (int i = 0; i < n; ++i) {
      size_t x;
      cin >> x;
      if (i % 2 == 1 && x % 2 == 0) {
        arr[0] += 1;
      } else if (i % 2 == 0 && x % 2 == 1) {
        arr[1] += 1;
      }
    }

    if(arr[0] == arr[1]) {
      cout << arr[0] << '\n';
      continue;
    }

    cout << -1 << '\n';
  }
}
