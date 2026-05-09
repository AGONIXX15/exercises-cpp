#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;


    long long sum = 0;
    int count_of_negatives = 0;
    for(long long i = 0; i < n; ++i) {
      long long x; cin >> x;
      if(x < 0) {
        count_of_negatives++;
      } else if(x == 0) {
        sum++;
      }
    }

    if(count_of_negatives % 2) {
      sum += 2;
    }

    cout << sum << '\n';
  }

  return 0;
}
