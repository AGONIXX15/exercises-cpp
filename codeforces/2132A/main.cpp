#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;

  while (t--) {
    list<char> l;

    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
      char c;
      cin >> c;
      l.push_back(c);
    }

    size_t m;
    cin >> m;
    string b;
    cin >> b;
    queue<char> list_b(b.begin(), b.end());

    for (size_t i = 0; i < m; ++i) {
      char c;
      cin >> c;
      if (c == 'V') {
        l.push_front(list_b.front());
      } else {
        l.push_back(list_b.front());
      }
      list_b.pop();
    }

    while (!l.empty()) {
      cout << l.front();
      l.pop_front();
    }
    cout << '\n';
  }

  return 0;
}
