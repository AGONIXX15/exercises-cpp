#include <bits/stdc++.h>

using namespace std;

struct Casino {
  size_t l;
  size_t r;
  size_t real;

  Casino(size_t l, size_t r, size_t real) : l(l), r(r), real(real) {}

  bool operator==(const Casino &other) const {
    return l == other.l && other.r == r && real == other.real;
  }
  bool operator<(const Casino &b) const { return l < b.l; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t;
  cin >> t;
  while (t--) {
    size_t n, c;
    cin >> n >> c;
    vector<Casino> v(n,Casino(0,0,0));
    for (size_t i = 0; i < n; ++i) {
      size_t l, r, real; cin >> l >> r >> real;
      v[i].l = l;
      v[i].r = r;
      v[i].real = real;
    }

    sort(v.begin(), v.end()); 

    size_t coins = c;
    for(size_t i = 0; i < n; ++i) {

      if(v[i].l <=coins && coins <= v[i].r && v[i].real > coins) {
        coins = v[i].real;
      }

    }
    cout << coins << '\n';
  }
}
