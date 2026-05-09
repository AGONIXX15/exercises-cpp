#include <bits/stdc++.h>

using namespace std;

int sum_digits(int n) {
  int d = 0;
  while (n) {
    d += n % 10;
    n /= 10;
  }
  return d;
}
int dp[7][55][2][2];
int dp2[7][55][2][2];


// ""
string n, m;
int f(int i, int sum, int l, int g) {
  if (i >= n.size())
    return sum;
  int &ans = dp[i][sum][l][g];
  if (ans != -1)
    return ans;
  ans = 1e6;

  int digit1 = (g == 0 ? m[i] - '0' : 0);
  int digit2 = (l == 0 ? n[i] - '0' : 9);
  for (int j = digit1; j <= digit2; ++j) {
    ans = min(ans, f(i + 1, sum + j, l || j < digit2, g || j > digit1));
  }
  return ans;
}

int min_sum;
int f2(int i, int sum, int l, int g) {
  if (i >= n.size()) {
    return sum == min_sum;
  }
  int &ans = dp2[i][sum][l][g];
  if (ans != -1)
    return ans;
  ans = 0;
  int digit1 = (g == 0 ? m[i] - '0' : 0);
  int digit2 = (l == 0 ? n[i] - '0' : 9);
  for (int j = digit1; j <= digit2; ++j) {
    ans += f2(i + 1, sum + j, l || j < digit2, g || j > digit1);
  }

  return ans;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  memset(dp, -1, sizeof(dp));
  // int m,n;   unordered_map<int,int> dct;
  cin >> m >> n;
  string m1 = "";
  for (int i = 0; i < n.size() - m.size(); ++i) {
    m1.push_back('0');
  }
  m1 += m;
  m = m1;
  // int minimum = 1e6;
  // for(int i = m; i <= n; ++i) {
  //   int result = sum_digits(i);
  //   minimum = min(minimum, result);
  //   dct[result]++;
  // }

  min_sum = f(0, 0, 0, 0);
  memset(dp2, -1, sizeof(dp2));

  
  cout << f2(0,0,0,0) << '\n';
  // cout << dct[minimum] << '\n';
  return 0;
}
