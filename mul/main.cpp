#include <bits/stdc++.h>

using namespace std;


//an = 0 | 1
// (13 * b) = (a0 * 1 + a1 * 2 + a2 * 4 a3 *8) * b
// a0,a2,a3 = 1
//
// (b + 4b +8b)
// a1 = 0



int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  // sumar todos los numeros desde 1 hasta n

  int n;
  cout << "Ingrese el n: ";
  cout.flush();
  cin >> n;

  cout << n*(n+1)/2 << '\n';




  return 0;
}
