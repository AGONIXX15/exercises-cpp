#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);


  size_t t; cin >> t;
  while(t--) {
    size_t l,a,b; cin >> l >> a >> b;


    vector<bool> vec(l,false);

    size_t max_value = a;
    for(size_t i = 1; i <= l; ++i) {
      size_t index = (a + i*b) % l;
      max_value = max(max_value,index);
      if(vec[index]) break;
      vec[index] = true;
    }
    cout << max_value << '\n';
  }
  return 0;
}
