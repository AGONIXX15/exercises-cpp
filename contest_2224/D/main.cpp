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



const ll MOD = 998244353;

struct Fraction {
    ll num, den;
};

// a/b < c/d
bool cmpFrac(const Fraction& a, const Fraction& b) {
    return (long double)a.num / a.den <
           (long double)b.num / b.den;
}

// val > x/y
bool greaterFrac(const Fraction& val, ll x, ll y) {
    return (long double)val.num / val.den >
           (long double)x / y;
}

ll modpow(ll a, ll e) {
    ll r = 1;

    while(e > 0) {
        if(e & 1)
            r = r * a % MOD;

        a = a * a % MOD;
        e >>= 1;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        for(auto& val : a)
            cin >> val;

        for(auto& val : b)
            cin >> val;

        vector<Fraction> ratios;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ratios.push_back({a[i], a[j]});
            }
        }

        sort(ratios.begin(), ratios.end(), cmpFrac);

        ll total_pairs = 1LL * n * (n - 1);
        ll good = 0;

        int m = ratios.size();

        for(int u = 0; u < n; u++) {
            for(int v = 0; v < n; v++) {
                if(u == v)
                    continue;

                ll x = b[v];
                ll y = b[u];

                int l = 0, r = m;

                while(l < r) {
                    int mid = (l + r) >> 1;

                    if(greaterFrac(ratios[mid], x, y))
                        r = mid;
                    else
                        l = mid + 1;
                }

                good += (m - l);
            }
        }

        good %= MOD;

        ll inv = modpow(total_pairs % MOD, MOD - 2);

        cout << good * inv % MOD << '\n';
    }
}
