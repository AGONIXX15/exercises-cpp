#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<ll> odd_el, even_el;
        for (int i = 0; i < n; i++) {
            if ((i + 1) & 1) odd_el.push_back(a[i]);
            else even_el.push_back(a[i]);
        }
        
        sort(odd_el.rbegin(), odd_el.rend());
        sort(even_el.rbegin(), even_el.rend());
        
        int odd_ops = 0, even_ops = 0;
        for (int i = 0; i < m; i++) {
            int xi; cin >> xi;
            if (xi % 2 == 1) odd_ops++;
            else even_ops++;
        }
        
        long long total = 0;
        for (auto x : a) total += x;
        
        long long marked = 0;
        int take_odd  = min(odd_ops,  (int)odd_el.size());
        int take_even = min(even_ops, (int)even_el.size());
        
        for (int i = 0; i < take_odd; i++) {
            if (i == 0 && odd_ops > 0) marked += odd_el[i];
            else if (odd_el[i] > 0)    marked += odd_el[i];
            else break;
        }
        
        for (int i = 0; i < take_even; i++) {
            if (i == 0 && even_ops > 0) marked += even_el[i];
            else if (even_el[i] > 0)    marked += even_el[i];
            else break;
        }
        
        cout << total - marked << "\n";
    }
    
    return 0;
}
