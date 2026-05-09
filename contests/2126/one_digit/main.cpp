#include <bits/stdc++.h>

using namespace std;

template<typename T>
void print_vector(vector<T>& v) {
  for(auto val: v) {
    cout << val << " ";
  }
  cout << '\n';
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n;
    cin >> n;
    int min_value = 1e9;
    while(n > 0) {
      int digit = n % 10;
      min_value = min(min_value, digit);
      n /= 10;
    }
    cout << min_value << '\n';
  }
  return 0;
}
