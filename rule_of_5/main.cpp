#include <cstring>
#include <iostream>
#include <utility>
#include <print>

/*
 C.21 if you define or = delete, any, copy, move, or destructor function, define
 or =delete all of them
 1. Destructor
 2. Copy Constructor
 3. Copy Assignment Operator
 4. Move constructor
 5. Move Assignment Operator
*/
using std::cout, std::endl;
struct SString {
  SString(const char *cp) : data(new char[strlen(cp) + 1]) {
    cout << "simplemente copiando" << endl;
    strcpy(data, cp);
  }

  SString(const SString &obj) : data(new char[strlen(obj.data) + 1]) {
    cout << "copiando desde otra direccion" << endl;
    strcpy(data, obj.data);
  }

  SString &operator=(const SString &rhs) {
    char *new_data = new char[strlen(rhs.data) + 1];
    strcpy(new_data, rhs.data);
    std::swap(new_data, data);
    delete[] new_data;
    return *this;
  }

  SString &operator=(SString &&rhs) {
    delete[] data;
    data = std::exchange(rhs.data, nullptr);
    return *this;
  }

  SString(SString &&rhs) noexcept : data(std::exchange(rhs.data, nullptr)) {}

  ~SString() {
    cout << "destructor..." << endl;
    delete[] data;
  }
  char *data;
};


int main() {
  SString algo1{"perro hp"};
  SString algo = std::move(algo1); // se movio la memoria ya no existe en algo1
  // cout << "algo.data = "<< algo.data << endl;
  std::println("hello world");

}
