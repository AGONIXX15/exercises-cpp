#include <bits/stdc++.h>

using namespace std;

struct Sort {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
  }
};

ostream &operator<<(ostream &os, const vector<pair<int, int>> &v) {
  for (auto p : v) {
    os << "(" << p.first << ", " << p.second << ") ";
  }
  return os;
}

const double PI = acos(-1);

const double radians(int angle) { return 1. * angle * PI / 180.0; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int angle, n;
  cin >> angle >> n;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    cin >> v[i].second;
  }

  sort(v.begin(), v.end());
  // cout << v << '\n';

  // cotanx = cat ady/cat op
  // cat op * cotanx = cat ady
  double new_distance = 1. * v[0].second * cos(radians(angle)) / sin(radians(angle));
  double shadow_distance = new_distance;
  double shadow_pos = v[0].first;
  double end_shadow = shadow_distance + shadow_pos;
  for (int i = 1; i < n; ++i) {
    int pos = v[i].first;
    int height = v[i].second;

    double new_distance =
        1. * height * cos(radians(angle)) / sin(radians(angle));

    double distance;
    // cout << (end_shadow >= pos) <<" " <<  (end_shadow < pos + new_distance) << '\n';
    // cout << "end_shadow: " << end_shadow << '\n';
   if(end_shadow >= pos && end_shadow < pos + new_distance) {
      distance = -end_shadow + new_distance + pos;
      end_shadow = pos + new_distance; 
      // cout << "distance: " << distance << '\n';
    }  else if(end_shadow >= pos) {
      continue;
    } else {
      distance = new_distance;
      end_shadow = pos + new_distance; 
    }
    shadow_distance += distance;

  }
  cout << fixed;
  cout << setprecision(14);
  cout << shadow_distance << '\n';
  return 0;
}
