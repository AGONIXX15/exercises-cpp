#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << '[';
  for(ll i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? ' ' : ", ");
  }
  os << ']';
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t n; cin >> n;
  vector<int> v(n);
  vector<int> sol(5,0);
  for(auto& val: v) {
    cin >> val;
    sol[val]++;
  }

  int sum = sol[4];

  sum += sol[3];
  int m = min(sol[1], sol[3]);
  sol[1] -= m;

  sum += sol[2] / 2;
  sol[2] %= 2;

  if(sol[2] == 1) {
    sum++;
    sol[1] = max(0, sol[1]-2);
  }

  sum += sol[1] / 4;
  sol[1] %= 4;
  sum += sol[1] > 0 ? 1: 0;
  cout << sum << '\n';
  



  return 0;
}
