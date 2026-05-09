#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  size_t t; cin >> t;
  while(t--) {
    int n,k; cin >> n >> k;
    vector<int> v(n);
    int min_element = 1e9;
    int max_element = -1e9;
    for(size_t i = 0; i < n; ++i){
      cin >> v[i];
      min_element = min(min_element,v[i]);
      max_element = max(max_element, v[i]);
    }
    // cout << "min_element: " << min_element << '\n';
    // cout << "max_element: " << max_element << '\n';
    
    stack<int> st;
    int maximum = -1;
    bool flag = false;
    
    for(size_t i = 0; i < n; ++i) {
      int val; cin >> val;
      if(flag) continue;
      if(v[i] > maximum && maximum != -1) {
        flag = true;
        continue;
      }


      if(val != -1) {
          int x = val + v[i];
        if(maximum == -1) {
          maximum = x;
          continue;
        }
        // cout << i << " x: " << x << '\n';
        // cout << "maximum: " << maximum << '\n';

        if(x != maximum) {
          flag = true;
          continue;
        }
        continue;
      }

      if(maximum != -1 && maximum - v[i] > k) {
        flag = true;
        continue;
      }
    }

    if (flag) {
      cout << 0 << '\n';
      continue;
    }

    if(maximum == -1) {
      int minimun = max_element - min_element;
      int maximun = min_element + k;
      // cout << "minimun: " << minimun << '\n';
      // cout << "maximum: " << maximun << '\n';
      // cout << "k: " << k << '\n';
      cout << abs(minimun - maximun) << '\n';
    } else {
      cout << 1 << '\n';
    }
    
    

  }
}

