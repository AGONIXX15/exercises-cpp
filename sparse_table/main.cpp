#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


template<typename T,size_t K, T (*F)(T a, T b)>
class SparseTable {


public:
  std::array<std::array<int,K>,25> arr;
  SparseTable<T,K,F>(std::vector<T>& v) {
    std::copy(v.begin(), v.end(), arr[0].begin());

    for(int i = 1; i <= K; ++i) {
      for(int j = 0;j + (1 << i) <= arr[0].size(); ++j) {
        arr[i][j] = F(arr[i-1][j], arr[i-1][j + (1 << (i - 1))]);
      }
    }
  }

  T get_value(long long l, long long r) {
    int sum = 1e9;
    for(int i = K;i >= 0; --i) {
      if((1 << i) <= r - l + 1) {
        sum = std::min(arr[i][l], sum);
        l += 1 << i;
      }
    }
    return sum;
  }
  

};


template <typename T, size_t K>
std::ostream& operator<<(std::ostream& os, const std::array<T,K>& arr) {
  os << '[';
  for(size_t i = 0; i < arr.size(); ++i) {
    os << arr[i] << (i == arr.size()-1 ? "":" ,");
  }
  os << ']';
  return os;
}

template<typename T, size_t K, T (*F)(T a, T b)>
std::ostream& operator<<(std::ostream& os, const SparseTable<T,K,F>& sp) {
  for(auto arr: sp.arr) {
    os << arr << '\n';
  }
  return os;
}

int suma(int a, int b) {
  return a + b;
}

int min(int a, int b) {
  return std::min(a,b);
}

int main() {


  std::vector<int> v = {1,2,3,4,5};
  SparseTable<int,5, min> sp(v);


  
  std::cout << sp << '\n';
  return 0;
}
