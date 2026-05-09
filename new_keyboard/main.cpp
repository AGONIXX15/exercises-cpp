#include <iostream>
#include <memory>
#include <initializer_list>


template <typename T>
class Vector {
  size_t _size;
  size_t _capacity;
std::unique_ptr<T[]> _data;


  size_t size() const {
    return _size;
  }

  auto begin() const {
    return _data.get();
  }

  auto end() const {
    return _data.get() + _size;
  }


public:
  Vector<T>(std::initializer_list<T> list) {
    _size = list.size();
    _capacity = _size * 2;
    _data = std::make_unique<T[]>(_capacity);
    std::copy(list.begin(), list.end(), begin());
  }

  
  T operator[](size_t index) const {
    if(index > _size) {
      throw std::logic_error("index out of bounds");
    }
    return _data.get()[index];
  }

friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
    os << "[";
    for(size_t i = 0; i < v.size(); ++i)  {
      os << v[i] << (i == v.size()-1 ? "": " ,");
    }
    os << "]";
    return os;
  }
};

int main() {
  Vector<int> v = {1,2,3,4,5,6,7};

  std::cout << v << std::endl;
  return 0;
}
