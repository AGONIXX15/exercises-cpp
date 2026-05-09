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


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;

        if (b < a) {
            if (a % 2 == 1 && a - 1 == b) {
                cout << y << '\n';
            } else {
                cout << -1 << '\n';
            }
            continue;
        }

        ll d = b - a;
        ll pairs = d / 2;
        ll extra = d % 2;

        ll cost = pairs * (x + min(x, y));

        if (extra) {
            if (a % 2 == 0) {
                cost += min(x, y);
            } else {
                cost += x;
            }
        }

        cout << cost << '\n';
    }

    return 0;
}
