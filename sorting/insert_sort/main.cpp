#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << '[';
  for(int i = 0; i < v.size(); ++i) {
    os << v[i] << (i+1 == v.size() ? "": ", ");
  }
  os << ']';
  return os;
}

void insert_sort(vector<int>& v) {

  for(int i = 1; i < v.size(); ++i) {
    int key = v[i];
    int insert_index = i;
    for(int j = i-1; j >= 0; --j) {
      if(v[j] > key) {
        cout << "state changing\n";
        cout << "i: " << i << " j: "<< j << '\n';
        cout << v << '\n';
        v[j+1] = v[j];
        cout << "after state changing\n";
        cout << v << '\n';
        insert_index = j;
      } else {
        cout << "i: " << i << " j: "<< j << " breaking" << '\n';
      }
    }
    v[insert_index] = key;
    cout << "inserted in index: " << insert_index << " value: " << key << '\n';
    cout << v << '\n';
  }
}


int main() {
  cin.tie(nullptr);
  vector<int> v = {11 ,12 ,3 ,4};
  insert_sort(v);
  // cout << v << '\n';
  ios::sync_with_stdio(0);
  return 0;
}
