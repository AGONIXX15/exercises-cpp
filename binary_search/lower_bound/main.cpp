#include <iostream>
#include <vector>
using namespace std;

int lower_bound(int m, vector<int>& v)  {
  int l = 0, r = v.size()-1;
  while(l <= r) {
    int mid = (l  + r)/2;
    if(m > v[mid])  {
      l = mid + 1;
    } else {
      r = mid -1;
    }
  }
  return l;
}

int main() {
  
  vector<int> v = {1, 2,3 ,4 ,5};
  cout << lower_bound(3,v) << '\n';
  return 0;
}
