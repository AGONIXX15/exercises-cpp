#include <bits/stdc++.h>

using namespace std;
template <typename T>
ostream& operator<<(ostream& os,vector<T>& v ) {
  for(auto& val: v) {
    os << val << " ";
  }
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n; cin >> n;
  vector<int> facts;
  while(n != 1)  {
    for(int i = 2; i < 251; ++i) {
      if(n % i == 0) {
        n /= i;
        facts.push_back(i);
        break;
      }
    }
  }

  cout << facts << '\n';

  return 0;
}
