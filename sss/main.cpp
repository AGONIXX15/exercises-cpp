#include <iostream>
#include <vector>


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  for(long long i = 0; i < v.size(); ++i) {
    os << v[i] << (i == v.size()-1 ? "":", ");
  }
  os << "]";
  return os;
}

template <typename T>
std::istream& operator<<(std::istream& is, T value) {
  std::cout << value;
  return is;
}

int main() {
  std::vector<int> v = {1,2,3,4,5};
  
  std::cin << "hola";
}
