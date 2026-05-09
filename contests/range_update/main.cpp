#include <bits/stdc++.h>

using namespace std;

int sum_of_digits(int n) {

  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    n /= 10;
    sum += digit;
  }
  return sum;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n, q;
    cin >> n >> q;

    vector<int> v(n);

    vector<int> counter(n,0);
    for (auto &val : v)
      cin >> val;

    for (size_t i = 0; i < q; ++i) {
      int option; cin >> option;

      if(option == 1) {
        int l, r; cin >> l >> r;

        l--;r--;
        for(;l <= r; ++l ) {

          counter[l]++;
        }
      } else {
        int index; cin >> index;
        index--;
        for(int i = 0; i < counter[index]; ++i) {
          v[index] = sum_of_digits(v[index]);
        }
        counter[index] = 0;
        cout << v[index] <<'\n';
      }
    }
  }

  return 0;
}
