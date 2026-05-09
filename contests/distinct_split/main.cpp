#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t t;
    cin >> t;
    while (t--) {
        size_t n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        unordered_set<char> left;
        size_t max_sum = 0;

        for (char c : s) {
            left.insert(c);
            if (--freq[c] == 0) freq.erase(c);

            size_t current_sum = left.size() + freq.size();
            max_sum = max(max_sum, current_sum);
        }

        cout << max_sum << '\n';
    }

    return 0;
}

