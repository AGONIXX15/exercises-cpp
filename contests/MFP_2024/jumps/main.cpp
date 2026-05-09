#include <bits/stdc++.h>

using namespace std;

int helper(vector<int>& v, int pos, int coins) {
  if(pos-1 >= v.size()) {
    return coins;
  }
  return max(helper(v, pos*2, coins + v[pos-1]), helper(v, pos*2+1, coins + v[pos-1]));
}
int func(vector<int>& v) {
  return helper(v,1,0);
}

template <typename T>
void print_vector(vector<T>& vec) {
  for (auto v: vec) {
    cout << v << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n; cin >> n;

  int size = pow(2,n) -1;
  vector<int> v(size);
  for(int i = 0; i < size; ++i) {
    int value; cin >> value;
    v[i] = value;
  }
  cout << func(v) << '\n';
  return 0;
}


