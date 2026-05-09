#include <bits/stdc++.h>

using ll = long long;
using namespace std;

bool canDeliver(ll time, vector<int>& v, int p) {
  ll pizzas = 0;
  for(ll t: v){
    pizzas += time/t;
    if (pizzas >= p) return true;
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int n,p; cin >> n >> p;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  ll low = 1, high = 1e18;
  while(low < high) {
    ll mid = (high + low) / 2;
    if(canDeliver(mid, v,p)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
}
