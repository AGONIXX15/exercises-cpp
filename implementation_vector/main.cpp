#include <iostream>

template <typename T> class MyVector {
  T *data = nullptr;
  size_t size;
  size_t cap;

public:
  MyVector() {
    size = 0;
    cap = 0;
  }

  ~MyVector() { delete[] data; }

  MyVector &operator=(const MyVector<T> &other) {
    if (this == &other)
      return *this;

    delete[] data;

    size = other.size;
    cap = other.cap;
    data = (cap > 0) ? new T[cap] : nullptr;

    for (size_t i = 0; i < size; ++i)
      data[i] = other.data[i];

    return *this;
  }

  MyVector(const MyVector<T> &other) {

    size = other.size;
    cap = other.cap;
    data = new T[cap];

    for (size_t i = 0; i < size; ++i)
      data[i] = other.data[i];
  }

  MyVector(MyVector &&other) noexcept
      : data(other.data), size(other.size), cap(other.cap) {
    other.data = nullptr;
    other.size = 0;
    other.cap = 0;
  }

  MyVector& operator=(MyVector<T>&& other) noexcept {
    if (this == &other) return *this;

    delete []data;
    data = other.data;
    size = other.size;
    cap = other.cap;

    other.data = nullptr;
    other.size = 0;
    other.cap = 0;
    return *this;
  }


  auto begin() { return data; }

  auto end() { return data + size; }

  auto begin() const { return data; }

  auto end() const { return data + size; }

  size_t length() {
    return this->size;
  }

  void resize(size_t new_cap) {
    T *new_array = new T[new_cap];
    for (size_t i = 0; i < size; ++i) {
      new_array[i] = data[i];
    }
    delete[] data;

    data = new_array;
    cap = new_cap;
  }

  void push_back(T value) {
    if (size == cap) {
      resize((cap == 0) ? 1 : cap * 2);
    }
    data[size++] = value;
  }

  friend std::ostream &operator<<(std::ostream &os, const MyVector<T> v) {
    for (auto value : v) {
      os << value << " ";
    }
    return os;
  }

  void insert(size_t index, T value) {
    if (index >= cap || index < 0) {
      throw std::out_of_range("index out of bounds");
    }

    if (size == cap) {
      resize(cap * 2);
    }

    for (size_t i = size; i > index; --i) {
      data[i] = data[i - 1];
    }
    data[index] = value;
    ++size;
  }

  T& operator[](size_t index) {
    return data[index];
  }

  const T& operator[](size_t index) const {
    return data[index];
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
