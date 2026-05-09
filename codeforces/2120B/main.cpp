#include <bits/stdc++.h>

using namespace std;

struct Vector {
  int dx, dy, x, y;

  Vector(int dx, int dy, int x, int y) : dx(dx), dy(dy), x(x), y(y) {}

  Vector(){}
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  size_t t;
  cin >> t;
  while (t--) {
    size_t n, s;
    cin >> n >> s;

    vector<Vector> vectors(n);
    for (size_t i = 0; i < n; ++i) {
      int dx, dy, x, y; cin >> dx >> dy >> x >> y;
      vectors[i].dx = dx;
      vectors[i].dy = dy;
      vectors[i].x = x;
      vectors[i].y = y;
    }

    for(size_t i = 0; i < 4; ++i) {
      for(size_t j = 0; j < n; ++j) {
      }
    }


  }
  return 0;
}
