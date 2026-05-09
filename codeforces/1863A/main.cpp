#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n,online,q; cin >> n >> online >> q;
    int offline = n - online;

    string s; cin >> s;
    
    int seen = online;
    if(seen == n) { 
      cout << "YES\n";
      continue;
    }
    int was_online = seen;
    online = 0;
    int flag = 0;
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] == '+') {
        was_online++;
        online++;
        offline--;
        if(seen + online == n) {
          flag = 1;
          cout << "YES\n";
          break;
        }
      } else {
        offline++;
        online--;

      }
    }
    if(flag) continue;
    
    else if(flag != 2 && was_online >= n) {
        cout << "MAYBE\n";
        flag = 2;
      continue;
      }

    if(flag == 0) cout << "NO\n";


  }
  return 0;
}
