#include <bits/stdc++.h>

using namespace std;
template <typename T>
void print_vector(vector<T>& ans) {
  for(auto& v: ans) {
    cout << v << " ";
  }
  cout << '\n';
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    vector<size_t> v(n);
    for(int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    vector<size_t> ans(n,0);
    int right = n-1;
    int left = 0;
    int index = 0;
    bool turn = true;

    while (left <= right) {
      if(turn) {
        ans[index++] = v[left++];
      } else {
        ans[index++] = v[right--];
      }
      turn = !turn;
    }
    print_vector(ans);
  }
  return 0;
}
