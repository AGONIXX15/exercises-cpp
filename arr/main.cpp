#include <iostream>
#include <array>


template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os,std::array<T,N>& arr) {
  os << "[";
  for(size_t i = 0; i < arr.size() ; ++i) {
    os << arr[i] << (i+1 < arr.size() ? ", ": "");
  }
  os << "]";
  return os;
}

int main() {
  std::array<int,26> arr;
  arr.fill(0);
  for(size_t i = 0; i < 26; ++i) {
    arr[i]++;
  }
  std::cout << arr << '\n';
  return 0;
}
