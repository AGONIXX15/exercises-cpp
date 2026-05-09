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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        long long lo = 0, hi = 0;
        long long sum = 0;

        bool ok = true;

        for (int i = 0; i < n; ++i) {
            char x = a[i], y = b[i];

            if (x == '(' && y == '(') {
                ++lo;
                ++hi;
                sum += 2;
            } else if (x == ')' && y == ')') {
                --lo;
                --hi;
                sum -= 2;
            } else {
                --lo;
                ++hi;
            }

            if (sum < 0) {
                ok = false;
                break;
            }

            lo = max(lo, 0LL);
            hi = min(hi, sum);

            int parity = (i + 1) % 2 == 1;
            if ((lo & 1) != parity) ++lo;
            if ((hi & 1) != parity) --hi;

            if (lo > hi) {
                ok = false;
                break;
            }
        }

        if (ok && sum == 0 && lo == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
