#include <bits/stdc++.h>

using namespace std;

template <typename T>


void set_vector(vector<T>& v) {

  for(auto& val: v) {
    cin >> val;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {

    size_t n; cin >> n;
    vector<long long> v1(n);
    set_vector(v1);

    vector<long long> v2(n);
    set_vector(v2);

    
    vector<long long> v3(n);
    set_vector(v3);
  }

  return 0;
}
