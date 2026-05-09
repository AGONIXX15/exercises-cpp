#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << '[';
  for(ll i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "": ", ");
  }
  os << ']';
  return os;
}

void merge(vector<int>& left, vector<int>& right, vector<int>& v) {
  int l,r,i;
  l = r = i = 0;
  while(l < left.size() && r < right.size()) {
    if(left[l] < right[r]) {
      v[i++] = left[l++];
    } else {
      v[i++] = right[r++];
    }
  }

  while(l < left.size()) {
    v[i++] = left[l++];
  }

  while(r < right.size()) {
    v[i++] = right[r++];
  }
}

void merge_sort(vector<int>& v) {
  if(v.size() == 1) return;
  int left_size = v.size() / 2;
  vector<int> left(v.begin(), v.begin() + left_size);
  vector<int> right(v.begin() + left_size, v.end());
  // cout << "left: " << left << " right: " << right << '\n';
  merge_sort(left);
  merge_sort(right);
  merge(left,right,v);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  vector<int> v = {4,3 ,2 ,1};
  // [4,3] [2,1]
  // [4] [3] = [3,4]
  // [2] [1] = [1, 2]
  // [3, 4] [1, 2] = [1,2,3,4]
  merge_sort(v);
  cout << v << '\n';

  return 0;
}
