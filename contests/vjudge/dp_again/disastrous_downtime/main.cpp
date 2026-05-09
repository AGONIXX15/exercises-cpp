#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  for (int i = 0; i < n; ++i)
    cin >> t[i];

  int max_overlap = 0;
  int j = 0;

  for (int i = 0; i < n; ++i) {
    // Move j to the first request outside the 1000ms window
    while (j < n && t[j] < t[i] + 1000)
      ++j;
    int overlap = j - i;
    max_overlap = max(max_overlap, overlap);
  }

  // Calculate minimum servers
  int servers_needed = (max_overlap + k - 1) / k; // ceil(max_overlap / k)
  cout << servers_needed << "\n";
  return 0;
}
