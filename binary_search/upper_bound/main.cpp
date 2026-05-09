#include <iostream>
#include <vector>

int upper_bound(const std::vector<int>& v, int target) {
  int l = 0, r = v.size();
  while(l < r) {
    int mid = l + (r - l) / 2;

    if(target >= v[mid]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

int lower_bound(const std::vector<int>& v, int target) {
  int l = 0, r = v.size();
  while(l < r) {
    int mid = l + (r - l) / 2;

    if(target > v[mid]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;

}


int main() {

  std::vector<int> v = {1,2,3,4,4,4,4};

  std::cout << upper_bound(v,4) << '\n';
  std::cout << lower_bound(v, 4) << '\n';


  return 0;
}
