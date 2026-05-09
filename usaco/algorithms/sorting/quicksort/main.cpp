#include <bits/stdc++.h>

using namespace std;


int partition(vector<int>& v, int left, int right) {

  int i = left-1; // ultimo indice donde sabemos que v[i] <= pivot
  int pivot = v[right];
  for(int j = left; j < right; ++j) {
    if(v[j] <= pivot) {
      i++;
      swap(v[j], v[i]);
    }
  }
  i++;
  swap(v[i],v[right]);
  return i;
}
void quicksort(vector<int>& v, int left, int right) {
  if(left >= right) return;
  int p = partition(v,left,right);
  quicksort(v,left, p-1);
  quicksort(v,p+1,right);
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(0);
  vector<int> v = {1,-2,5,10};
  quicksort(v,0,v.size()-1);
  for(auto val: v) cout << val << " ";

  return 0;
}
