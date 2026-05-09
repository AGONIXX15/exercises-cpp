#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int start_value = v[k - 1];

    sort(v.begin(), v.end());

    int index = find(v.begin(), v.end(), start_value) - v.begin();

    int curr_height = v[index];
    int water_level = 1;
    bool flag = true;
    int max_height = v[v.size()-1];

    while (index != n-1) {
      if(curr_height == max_height) break;
      int next_height = v[index + 1];
      int diff = next_height - curr_height;

      if(water_level + diff <= curr_height+1) {
        curr_height = next_height;

        if(curr_height == max_height) break;
        index++;
        water_level += diff;
      } else {
        flag = false;
        break;
      }
    }

    cout << (flag ? "YES" : "NO") << '\n';
  }

  return 0;
}

