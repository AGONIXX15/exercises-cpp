#include <iostream>
#include <vector>

void merge(std::vector<int>& v,int l, int mid, int r) {
  
  std::vector<int> temp;
  int i = l;
  int j = mid+1;
  while(i <= mid && j <= r) {
      if(v[i] <= v[j]) {
      temp.push_back(v[i]);
      i++;
    } else {
      temp.push_back(v[j]);
      j++;
    } 
  }
  while(i <= mid) {
    temp.push_back(v[i]);
    i++;
  }
  while(j <= r) {
    temp.push_back(v[j]);
    j++;
  }

  for(int i = 0; i < temp.size(); ++i) {
    v[i+l] = temp[i];
  }
}

void merge_sort(std::vector<int>& v, int l, int r) {
  if(l >= r) return;
  int mid = (l + r)/2;
  merge_sort(v,l,mid);
  merge_sort(v,mid+1,r);
  merge(v,l,mid,r);
}

int main() {

  std::vector<int> v = {5,3,2,1,9,2};
  merge_sort(v,0,v.size()-1);
  for(auto& val: v) std::cout << val << " ";
  std::cout << '\n';
  return 0;
}
