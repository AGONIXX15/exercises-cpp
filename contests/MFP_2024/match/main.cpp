#include <bits/stdc++.h>

using namespace std;



int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t n; cin >> n;
  int count1 = 0, count2 = 0;
  while(n--){
    string s,i,p; cin >> s >> i >> p;

    if(i[0] == '1') count1 += p[1] - '0';
    
    if(i[0] == '2') count2 += p[1] - '0';
  }
  cout << count1 << " x " << count2 << '\n';
}

