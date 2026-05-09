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


pair<double,double> quadratic(double a, double b, double c) {
  double p1 = (-b + sqrt(b*b -4*a*c))/(2.0*a);
  double p2 = (-b - sqrt(b*b -4*a*c))/(2.0*a);
  return {p1,p2};
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    pair<int,int> p,q;
    cin >> p.first >> p.second >> q.first >> q.second;
    vector<int> distances(n);
    for(auto& val: distances) cin >> val;
    // (px - x)**2 (px - y)**2
    // (px - x) (px - x) px^2 -2px(x) + x^2
    // py^2 -2py(y) + y²
    // (1+m)x^2 + 2xpx + d^2-px^2 -2py^2 = 0
    // x2 - x1/y2 - y1 = m
    // y = mx + y1
    // (1,1) (3,3) 2
    double m = 1.0 * (p.first - q.first)/(p.second - q.second);
    double a = 1 + m;
    double b = 2*p.first;
    double c = 2-p.first*p.first -2*p.second*p.second;
    pair<double,double> result = quadratic(a,b,c);
    cout << result.first << " " << result.second << '\n';
  }
  return 0;
}
