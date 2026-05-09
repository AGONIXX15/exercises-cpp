#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T> &vec)  {
  for(auto val: vec) {
    os << val << " ";
  }
  return os;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;

    vector<int> vec(n);
    vector<int> cnt(n+1);
    for(auto& iter: vec) {
      cin >> iter;
      ++cnt[iter];
    }

    
    int count = 0;
    for(int l = 0; l <= n; ++l) {
      int sum = 0;
      for(int r = l; r < n; ++r){
        sum += vec[r];
        if(l == r) continue;
        if(sum <= n) {
          count += cnt[sum];
          cnt[sum] = 0;
        }
      }
    }

    cout << count << '\n';
    

  }
  return 0;
}
