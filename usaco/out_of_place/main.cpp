#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << '[';
  for(int i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "": ", ");
  }
  os << ']';
  return os;
}

template <typename A, typename B>
ostream& operator<<(ostream& os, pair<A,B>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename K,typename T>
ostream& operator<<(ostream& os, unordered_map<K,T>& dct) {
  os << "{";
  int i = 0;
  for(auto& [key, value]: dct ) {
    os << "{" << key << ": " << value << (++i != dct.size() ? "}, ": "}");
  }
  os << "}";
  return os;
}




int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int n; cin >> n;
  vector<int> v(n);
  for(auto& val: v) cin >> val;
  vector<int> st;
  int steps = 0;
  for(int i = 0; i < n; ++i) {
    while(!st.empty() && st[st.size()-1] >= v[i])  {
      if(st.size() >= 2 && st[st.size()-1] == st[st.size()-2]) {
        st.pop_back();
        st.pop_back();
      } else st.pop_back();
      steps++;
    } 
    st.push_back(v[i]);
  }
  cout << steps << '\n';

  return 0;
}
