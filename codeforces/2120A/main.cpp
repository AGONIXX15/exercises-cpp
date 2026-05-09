#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  size_t t;
  cin >> t;
  while (t--) {
    size_t arr[] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 6; ++i) {
      size_t x;
      cin >> x;
      arr[i] = x;
    }
    int l1 = arr[0], b1 = arr[1];
    int l2 = arr[2], b2 = arr[3];
    int l3 = arr[4], b3 = arr[5];

    if (l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1) {
      cout << "YES\n"; // Caso A
    } else if (b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1) {
      cout << "YES\n"; // Caso B
    } else if (l2 == l3 && l1 == l2 + l3 && b1 == b2 + b3) {
      cout << "YES\n"; // Caso C
    } else if (b2 == b3 && b1 == b2 + b3 && l1 == l2 + l3) {
      cout << "YES\n"; // Caso D
    } else {
      cout << "NO\n";
    }
  }
}
