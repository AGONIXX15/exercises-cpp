#include <bits/stdc++.h>

using namespace std;

pair<double, double> quadratic_equation(double a, double b, double c) {
  double s1 = (-b + sqrt(b*b -4*a*c))/2.0;
  double s2 = (-b - sqrt(b*b-4*a*c))/2.0;
  return {s1,s2};
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  double a,m; cin >> a >> m;

  double b = (2*a  +1);
  double c = 2*a -2 -2*m;
  pair<double, double> sol = quadratic_equation(1,b,c);
  cout << max(sol.first,sol.second) << '\n';
  
  return 0;
}
