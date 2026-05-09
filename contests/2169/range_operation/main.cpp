#include <bits/stdc++.h>

using namespace std;


float calculate_equation(int a, int b, int c) {

  if(pow(b,2) -4*a*c >= 0) {
    return 1.0 * (-b + sqrt(pow(b,2)-4*a*c))/2;
  }

  return -1;
}

bool is_integer(float x) {
  return x == static_cast<int>(x);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;


    // (i+x)*(i+x+1) =  -(range sum) + sum
    // i² + ix + i + ix + x² + x > -rangesum + sum
    //  a = 1
    //  b = 2i + 1
    //  c = i + i² + rangesum - sum
    //  x² +  2ix + x + i + i²
    //  x² + x(2i + 1) + i + i²


  }

  return 0;
}
