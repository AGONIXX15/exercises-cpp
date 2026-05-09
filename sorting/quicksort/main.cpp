#include <iostream>
#include <vector>

int partition(std::vector<int>& v, int l, int r) {
  int pivot = v[r];
  int i = l-1;
  for(int j = l; j < r; ++j) {
    if(v[j] <= pivot) {
      i++;
      std::swap(v[i],v[j]);
    }
  }
  std::swap(v[i+1],v[r]);
  return i+1;
}

// [l,r]
void quicksort(std::vector<int>& v,int l, int r) {
  if(l >= r) return;
  int p = partition(v,l,r);
  quicksort(v,l,p-1);
  quicksort(v,p+1,r);
}

int main() {
  std::vector<int> v = {2,3,1,2};
  quicksort(v,0,v.size()-1);
  for(auto val: v) std::cout << val << " ";
  std::cout << '\n';
  return 0;
}
