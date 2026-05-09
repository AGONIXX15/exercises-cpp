#include <iostream>
#include <memory>

template <typename T> class MyVector {
  std::unique_ptr<T[]> data;
  size_t _size;
  size_t cap;

public:
  MyVector() {
    _size = 0;
    cap = 0;
  }



  auto begin() { return data.get(); }

  auto end() { return data.get() + _size; }

  auto begin() const { return data; }

  auto end() const { return data + _size; }

  size_t size() {
    return this->_size;
  }

  void resize(size_t new_cap) {
    std::unique_ptr<T[]> new_array = std::make_unique<T[]>(new_cap);
    for (size_t i = 0; i < _size; ++i) {
      new_array.get()[i] = data.get()[i];
    }

    data = std::move(new_array);

    cap = new_cap;
  }

  void push_back(T value) {
    if (_size == cap) {
      resize((cap == 0) ? 1 : cap * 2);
    }
    data.get()[_size++] = value;
  }

  friend std::ostream &operator<<(std::ostream &os, const MyVector<T>& v) {
    for (auto value : v) {
      os << value << " ";
    }
    return os;
  }

  void insert(size_t index, T value) {
    if (index >= cap || index < 0) {
      throw std::out_of_range("index out of bounds");
    }

    if (_size == cap) {
      resize(cap * 2);
    }

    for (size_t i = _size; i > index; --i) {
      data.get()[i] = data.get()[i - 1];
    }
    data.get()[index] = value;
    ++_size;
  }

  T& operator[](size_t index) {
    return data.get()[index];
  }

  const T& operator[](size_t index) const {
    return data.get()[index];
  }
};

int main() {
  MyVector<int> v;
  for (int i = 0; i < 1'000'000; ++i) {
    v.push_back(i);
  }
  for (auto val : v) {
    std::cout << val << " ";
  }
  std::cout << '\n';

}
