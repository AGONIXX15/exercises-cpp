#include <iostream>
#include <unordered_map>
#include <string>


// template <typename T, typename K>
// using Map = std::unordered_map<K,T>;

template <typename T> class Vector {
  T *arr;
  size_t capacity;
  size_t size;

public:
  Vector<T>(int capacity) {
    this->capacity = capacity;
    size = 0;
    arr = new T[capacity];
  }

  Vector(const Vector<T>& v) {

  }

  Vector<T> operator=(Vector<T>& v) {

  }

  Vector<T>(Vector<T>&& v) {

  }

  Vector<T> operator=(Vector<T>&& v) {

  }


  Vector<T>(std::initializer_list<T> list) {
    size = list.size();
    capacity = size * 2;
    arr = new T[capacity];
    int index = 0;
    for (T algo : list) {
      arr[index++] = algo;
    }
  }

  ~Vector() {
    delete [] arr;
  }

  auto begin() {
    return arr;
  }

  auto end() {
    return arr + size;
  }

  void resize(size_t new_cap) {
    T *new_arr = new T[new_cap];
    for (int i = 0; i < size; i++) {
      new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_cap;
  }

  void add(T data) {
    if (size == capacity) {
      resize((capacity == 0) ? 1 : capacity * 2);
    }
    arr[size++] = data;
  }

  T operator[](size_t index) {
    if (index >= size) {
      throw std::runtime_error("trying to access an invalid index");
    }
    return arr[index];
  }

  friend std::ostream &operator<<(std::ostream &os, const Vector &v) {
    os << "[";
    for (int i = 0; i < v.size; i++) {
      os << std::to_string(v.arr[i]) << (i == v.size-1 ? "": ", ");
    }
    os << "]";
    return os;
  }
};

int main() {

  Vector<int> v = {1,2,3,4,5};
  std::cout << v << '\n';
}
