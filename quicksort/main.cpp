#include <iostream>
#include <vector>


int partition(std::vector<int>& v, int start, int end) {

  int pivot = v[end];
  int i = start-1;
  for(int j = start; j <= end-1;j++) {
    if(v[j] < pivot) {
      i++;
      std::swap(v[i],v[j]);
    }
  }
  i++;
  std::swap(v[i],v[end]);
  return i;
}

void quicksort(std::vector<int>& v, int start, int end) {
  if(end <= start) return;

  int pivot = partition(v,start,end);
  quicksort(v,start,pivot-1);
  quicksort(v,pivot+1,end);
}



int main() {
  std::vector<int> v = {4,3,1,5,10,20,30};
  quicksort(v,0,v.size()-1);
  for(size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
