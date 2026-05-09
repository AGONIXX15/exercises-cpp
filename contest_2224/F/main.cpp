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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<pair<int,int>> ord;

        for (int i = 1; i <= n; i++)
            ord.push_back({a[i], i});

        sort(ord.begin(), ord.end());

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (ord[i].first > i + 1) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "No\n";
            continue;
        }

        vector<int> nxt(n + 1);

        for (int i = 0; i < n; i++) {
            nxt[ord[i].second] = i + 1;
        }

        vector<int> visit(n + 1, 0);
        vector<vector<int>> cycles;

        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                vector<int> cyc;

                int u = i;

                while (!visit[u]) {
                    visit[u] = 1;
                    cyc.push_back(u);
                    u = nxt[u];
                }

                cycles.push_back(cyc);
            }
        }

        for (int i = 1; i < (int)cycles.size(); i++) {
            int x = cycles[i - 1][0];
            int y = cycles[i][0];

            swap(nxt[x], nxt[y]);
        }

        vector<int> ans;

        int start = 1;
        vector<int> used(n + 1, 0);

        int u = start;

        while (!used[u]) {
            used[u] = 1;
            ans.push_back(u);
            u = nxt[u];
        }

        if ((int)ans.size() != n || u != start) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        for (int x : ans)
            cout << x << ' ';

        cout << '\n';
    }
}
