#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    size_t n; cin >> n;
    vector<size_t> vec(n);
    for(size_t i = 0; i < n; ++i) cin >> vec[i];
    // false = alice, true = bob
    bool turn = true;
    int l = 1, r = n-1;
    size_t max_candies = vec[0];
    size_t moves = 1;
    size_t alice_candies = vec[0], bob_candies = 0;

    while(l <= r) {
      size_t current_candies = 0;
      bool flag = false;
      while (turn && current_candies <= max_candies) {
        
        if(r >= l) {
          bob_candies += vec[r];
          current_candies += vec[r--];
          flag = true;
        } else {
          break;
        }
      }

      while(!turn && current_candies <= max_candies) {
        if(l <= r) {
          alice_candies += vec[l];
          current_candies += vec[l++];
          flag = true;
        } else {
          break;
        }
      }

      if(!flag) break;

      turn = !turn;
      max_candies = current_candies;
      moves++;
    }
    
    cout << moves << " " << alice_candies << " " << bob_candies << '\n';
  }
  return 0;
}
