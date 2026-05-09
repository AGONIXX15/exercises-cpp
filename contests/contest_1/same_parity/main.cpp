#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
      size_t n,k; cin >> n >> k;

    size_t value = ceil(1.* k/(n-1))*n;
    int difference = k - ceil(1.*k/(n-1))*(n-1);
    cout <<  value-1-abs(difference) << '\n';




  }
  return 0;
}
