#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  // 0 <= i < n - i
  while(t--) {

    size_t n, k; cin >> n >> k;
    string s; cin >> s;
    unordered_map<int,int> counter;

    for(auto character: s) counter[character - '0']++;
    // for cancel one operation with need a one from 1 an a zero from zero
    // k = 2
    // 3 0 2 1
    // 00011
    int zeros = counter[0] / 2;
    int res_zeros = counter[0] % 2;

    int ones = counter[1] / 2;

    int res_ones = counter[1] % 2;
    int sum = zeros + ones;

    if(!((res_zeros == 0 && res_ones == 0)|| (res_zeros == 1 && res_ones == 1))) {
      zeros--;
      ones--;
      sum--;
    }
    // sum = palindromes x + palindromes y
    // sum - 2*a = k
    // sum - k = 2*a
    // 
    // (sum - k)*1/2 = a
    //
    // palindromes x + palindromes y = k
    // palindromes x = k - palindromes y
    // 2 1

    int a = (sum - k) * 1/2;

    if(a <= min(zeros, ones) && sum - 2*a == k) {
      cout << "YES" << '\n';
      continue;
    }
    cout << "NO" << '\n';
  }

  return 0;
}
