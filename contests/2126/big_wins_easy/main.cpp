#include <bits/stdc++.h>
using namespace std;

int get_median(const vector<int>& freq, int len) {
    int count = 0;
    int target = (len + 1) / 2;
    for (int i = 1; i <= 100; ++i) {
        count += freq[i];
        if (count >= target) return i;
    }
    return -1; // no debería pasar
}

int get_min(const vector<int>& freq) {
    for (int i = 1; i <= 100; ++i)
        if (freq[i]) return i;
    return -1; // no debería pasar
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> freq(101, 0);
            for (int j = i; j < n && j - i + 1 <= 100; ++j) {
                freq[a[j]]++;
                int len = j - i + 1;
                int med = get_median(freq, len);
                int mini = get_min(freq);
                ans = max(ans, med - mini);
            }
        }
        cout << ans << '\n';
    }
}
