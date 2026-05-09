#include <bits/stdc++.h>
using namespace std;

template <typename T, typename K>
ostream& operator<<(ostream& os, unordered_map<T,K>& dct) {
  os << "{\n";
  for(auto it = dct.begin();  it != dct.end(); ++it) {
    os << "{ " << it->first << ": " << it->second << " }\n";
  }
  os << "}\n";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, unordered_set<T>& st) {
  os << '{';
  for(auto it = st.begin(); it != st.end(); ++it) {
    os << *it << " ";
  }
  os << '}';
  return os;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) {
    int n,k; cin >> n >> k;

    vector<int> v(n);
    for(auto& val: v) cin >> val;
    vector<int> b(n);

    
    unordered_set<int> exists;
    bool ex = false;
    for(auto& val: b)  {
      cin >> val;
      if(val != -1 && exists.count(val)) {
        cout << "NO\n";
        ex = true;
      }
      exists.insert(val);
    }
    if(ex) continue;
  
    
    unordered_set<int> st;
    
    for(int i = 0; i < k; ++i) {
      st.insert(v[i]);
    }
    unordered_set<int> mark;
    int count = 0, count_zeros = 0;
    for(int i = 0; i < k; ++i) {
      if(b[i] == -1) count_zeros++;
      else if(!st.count(b[i])) count++;
      else if(st.count(b[i]) && mark.count(b[i])) count++;
      else if(st.count(b[i])) mark.insert(b[i]);
    }

    bool flag = true;
    for(int i = k; i < n; ++i)  {
      // cout << "count_zeros: " << count_zeros << endl;
      // cout << "count: " << count << endl;
      
      if(count_zeros - count != 0 && count != 0) {
        flag = false;
        break;
      }

      // erase element
      // cout << "erasing " << mark;
      st.erase(v[i-k]);
      if(b[i-k] == -1) count_zeros--;
      else if(st.count(b[i-k])) count--;
      mark.erase(v[i-k]);

      st.insert(v[i]);
      if(st.count(b[i]) && mark.count(b[i])) count++;
      else if(!st.count(b[i]) && b[i] != -1)  count++;
      else if(b[i] == -1) count_zeros++;
      mark.insert(b[i]);
      // cout << "adding mark " << mark << '\n';
      // cout << "count: " << count << '\n';
      // cout << "count_zeros: " << count_zeros << '\n';
    }

    if(count_zeros - count != 0 && count != 0) {
      flag = false;
    }

    cout << (flag ? "YES": "NO") << '\n';
  }
  return 0;
}
