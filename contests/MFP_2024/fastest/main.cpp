#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;

  Point(int x, int y) : x(x), y(y) {}

  long double distance(Point other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
  }
};

int find(vector<int> &v, int x) {
  if (v[x] != x) {
    v[x] = find(v, v[x]);
  }
  return v[x];
}

void unite(vector<int> &v, int a, int b) {
  a = find(v, a);
  b = find(v, b);
  if (a != b) {
    v[b] = a;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int n, q, d;
  cin >> n >> q >> d;
  vector<Point> v(n, Point(0, 0));
  vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    vec[i] = i;
    v[i] = Point(x, y);
  }

  // O(n²)
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i + 1; j < v.size(); ++j) {
      if (v[i].distance(v[j]) <= d) {
        unite(vec, i, j);
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    int s, t;
    cin >> s >> t;
    cout << ((find(vec, s - 1) == find(vec, t - 1)) ? "S" : "N") << '\n';
  }
}
