#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int parent[MAXN], size_set[MAXN];

int find(int x) {
  if (x != parent[x]) parent[x] = find(parent[x]);
  return parent[x];
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    if (size_set[a] < size_set[b]) swap(a, b);
    parent[b] = a;
    size_set[a] += size_set[b];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
    size_set[i] = 1;
  }

  for (int i = 0; i < m; ++i) {
    vector<int> group(k);
    for (int j = 0; j < k; ++j) {
      cin >> group[j];
    }
    for (int j = 1; j < k; ++j) {
      unite(group[0], group[j]);
    }
  }

  int c;
  cin >> c;
  unordered_set<int> infected;
  vector<int> infected_list(c);
  for (int i = 0; i < c; ++i) {
    cin >> infected_list[i];
    infected.insert(infected_list[i]);
  }

  unordered_set<int> infected_components;
  for (int x : infected_list) {
    infected_components.insert(find(x));
  }

  vector<int> quarantine;
  for (int i = 1; i <= n; ++i) {
    if (!infected.count(i) && infected_components.count(find(i))) {
      quarantine.push_back(i);
    }
  }

  sort(quarantine.begin(), quarantine.end());
  cout << quarantine.size() << '\n';
  for (int x : quarantine) cout << x << ' ';
  cout << '\n';

  return 0;
}

