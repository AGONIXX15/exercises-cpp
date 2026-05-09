#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int ans = 1;
    int last; cin  >> last;
    for(int i = 1; i < n; ++i){
      int x; cin >> x;
      if(last+1 < x){
        ++ans;
        last = x;
      }
    }
    cout << ans << endl;
  }
}
