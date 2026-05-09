#include <iostream>
#include <utility>

template <typename T>
class UniquePtr {
  T* data_;
public:

  UniquePtr(T* data) {
    this->data_ = data;
  }


  UniquePtr(const UniquePtr&) = delete;

  UniquePtr& operator=(const UniquePtr&) = delete;

  UniquePtr(UniquePtr&& p): data_(p.data_) {
    p.data_ = nullptr;
  }

  ~UniquePtr() {
    std::cout << "deleting automatically" << std::endl;
    delete data_;
  }
  
  UniquePtr& operator=(UniquePtr&& p) {
    if(this != &p) {
      delete data_;
      data_ = p.data_;
      p.data_ = nullptr;
    }
    return *this;
  }

  T* get() {
    return this->data_;
  }

  T* release() {
    auto temp = this->data_;
    this->data_ = nullptr;
    return temp;
  }


  void reset(T* data) {
    if(data != data_) {
      delete data_;
    }
    this->data_ = data;
  }

  void swap(UniquePtr& p) {
    std::swap(p.data_,data_);
  }

};


template <typename T, typename... Args>
UniquePtr<T> make_unique(Args&&... arg) {
  return UniquePtr<T>(new T(std::forward<Args>(arg)...));
}



int main() {

  return 0;
}
