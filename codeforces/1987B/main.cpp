#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    // cout << "otro\n";
    priority_queue<ll,vector<ll>, greater<ll>> pq;
    int n; cin >> n;
    vector<ll> v(n);
    for(auto& val: v) cin >> val;
    
    int l = 0;
    for(int i = 0; i < n; ++i) {
      if(v[i] > v[l]) {
        l = i;
      } else  {
        ll res = v[l] - v[i];
        if(res == 0) continue;
        // cout << res << '\n';
        pq.push(res);
      }
    }

    // while(!pq.empty()) {
    //   cout << pq.top() << ' ';
    //   pq.pop();
    // }
    // cout << '\n';
    ll sum = 0;
    ll last = 0;
    while(!pq.empty()) {
      ll cur = pq.top(); 
      ll cost = (pq.size() + 1) * (cur - last);
      sum += cost;
      last = cur;pq.pop();
    }
    cout << sum << '\n';
  }
  return 0;
}
