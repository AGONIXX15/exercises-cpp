#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);

  int n; cin >> n;


  string arr[] = {"I hate it", "I love it"};
  for(int i = 0; i < n; ++i) {
    


    if (i == n-1) {
      cout << arr[i % 2] << '\n';
      break;
    }

    if(i % 2 == 0) {
      cout << "I hate that ";
    } else {
      cout << "I love that ";
    }
    
  }

  return 0;
}
