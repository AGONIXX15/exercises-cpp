#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Cmp {
  // a debe ir primero que b?
  bool operator()(int a, int b) {
    return a > b;
  }
};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << '[';
  for(ll i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "": ", ");
  }
  os << ']';
  return os;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  vector<int> v = {1, 4 ,6 ,8};

  sort(v.begin(), v.end(), Cmp());
  cout << v << '\n';
  return 0;
}
