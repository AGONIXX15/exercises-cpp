#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os,vector<T> &vec ) {
  for(auto val: vec) {
    os << val << " ";
  }
  return os;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(0);

  size_t n,m,k; cin >> n >> m >> k;
  vector<long long> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());
  // cout << v << '\n';
  // 9 3 3
  // 1 3 4 5 5 6 7 8 9 
  // 7 + 8 +9 +6 + 5 +5 +4

  long long sum = 0;
  long long range = m+((m-1)*(k-1));
  for(int i = n-1; i >= n-range; --i) {
    sum += v[i];
  }

  
  cout << sum << '\n';

  return 0;
}
