#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << '[';
  for(int i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "": ", ");
  }
  os << ']';
  return os;
}

template <typename A, typename B>
ostream& operator<<(ostream& os, pair<A,B>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename K,typename T>
ostream& operator<<(ostream& os, unordered_map<K,T>& dct) {
  os << "{";
  int i = 0;
  for(auto& [key, value]: dct ) {
    os << "{" << key << ": " << value << (++i != dct.size() ? "}, ": "}");
  }
  os << "}";
  return os;
}



int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n,k; cin >> n >> k;
    vector<int> v(n);
    int minimum = 1e7;
    int maximum = -1e7;
    int sum = 0;
    unordered_map<int,int> dct;
    for(auto& val: v) {
      cin >> val;
      minimum = min(minimum,val);
      maximum = max(maximum, val);
      sum += val;
      dct[val]++;
    }

    int x = k - maximum + minimum;
    if(x < -1 || (x == -1 && dct[maximum] > 1)) {
      cout << "Jerry\n";
      continue;
    } else if(x == -1) {
      dct[maximum]--;
      maximum--;
      dct[maximum]++;
    }

    int cantity = sum - (maximum + minimum)  -minimum*(n-2);

    cout << "sum: " << sum << " max: " << maximum << " min: " << minimum << " x: " << x << " cantity: " << cantity << '\n';

    cout << (sum % 2 == 0 ? "Tom": "Jerry") << '\n';
  }
  return 0;
}
