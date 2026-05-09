#include <bits/stdc++.h>

using namespace std;

void reset_value(vector<int>& v) {
  int index = -1;
  int mx = -1e7;
  for(int i = 0; i < v.size(); ++i) {
    if(v[i] > mx) {
      index = i;
      mx = v[i];
    }
  }
  v[index] = 0;
}

template <typename T>
ostream& operator<<(ostream& os,vector<T>& v) {
  os << '[';
  for(int i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "": ", ");
  }
  os << ']';
  return os;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n,m,l; cin >> n >> m >> l;
    // m animatronics
    // n flaslight events
    // l length of the night

    // simulate if it works just assume
    vector<int> v(n);
    for(auto& val: v) cin >> val;

    vector<int> animatronics(m,0);
    
    int index1 = 0;
    int index2 = 0;
    for(int i = 1; i <= l; ++i) {
      if(index1 < n && v[index1] == i) {
        index1++;
        reset_value(animatronics);
      }
      animatronics[index2]++;
      index2 = (index2 + 1) % m;
    }
    cout << animatronics << '\n';
  }
  return 0;
}
