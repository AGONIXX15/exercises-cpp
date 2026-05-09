#include <bits/stdc++.h>

using namespace std;


// bool find_if_diferent_digits(size_t x) {
//   unordered_set<int> set;
//   while(x > 0) {
//     int digit = x % 10;
//     if(set.count(digit)) {
//       return false;
//     }
//     x /= 10;
//     set.insert(digit);
//   }
//   return true;
// }



int dp[5][1 << 10][2];
string year;
bool can(int pos, int mask, int greater) {
  if(pos == year.size()) return greater;

  int& ans = dp[pos][mask][greater];
  if(ans != -1) return ans;

  ans = 0;
  for(int d = 0; d <= 9; ++d) {
    if(pos == 0 && d == 0) continue;
    if(mask & (1 << d)) continue;

    if(!greater && d < (year[pos] - '0')) continue;

    bool new_greater = greater || (d > (year[pos] - '0'));
    if(can(pos+1,mask | (1 << d), new_greater)) {
      ans = 1;
      return ans;
    }
  }
  ans = 0;
  return ans;
}

string res;

string f() {
  int mask = 0;
  bool greater = false;
  for(int i = 0; i < 4; ++i) {
    for(int d = 0; d <= 9; ++d) {
      if(i == 0 && d == 0) continue;
      if(!greater && d < (year[i] - '0')) continue;
      if(mask & (1 << d)) continue;

      bool new_greater = greater || (d > (year[i] - '0'));
      if(can(i+1, mask | (1 << d),new_greater)) {
        res += char('0' + d);
        mask = mask | (1 << d);
        greater = new_greater;
        break;
      }
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  memset(dp,-1,sizeof(dp));
  int y; cin >> y;
  year = to_string(y);
  // size_t year;
  // cin >> year;
  // for (size_t i = year + 1; i < 10000; ++i) {
  //   
  //   if(find_if_diferent_digits(i)) {
  //     cout << i << '\n';
  //     break;
  //   }
  // }
  cout << f() << '\n';
  return 0;
}
