#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  size_t t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2021 == 0 || n % 2020 == 0) {
      cout << "yes\n";
      continue;
    }
    unordered_set<long long> n2021;

    // precomputacion
    bool find = false;
    for (int i = 1; i * 2021 <= n; ++i) {
      n2021.insert(i * 2021);
      long long number = n - ((i * 2020) % n);
      if (n2021.find(number) != n2021.end()) {
        find = true;
        break;
      }
    }


    if (find) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}
