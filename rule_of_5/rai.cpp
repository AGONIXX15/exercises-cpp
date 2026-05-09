#include <cstring>
#include <iostream>
#include <memory>

// first RAII pass
/* struct SString {
  SString(char const *cp) : data(new char[strlen(cp) + 1]) {
    strcpy(data.get(), cp);
  }
  std::shared_ptr<char[]> data;
}; */


// second RAII pass
struct SString {
  SString(char const *cp) : data(new char[strlen(cp) + 1]) {
    strcpy(data.get(), cp);
  }

  SString(SString const &rhs) : data(new char[strlen(rhs.data.get()) + 1]) {
    strcpy(data.get(), rhs.data.get());
  }

  SString &operator=(SString const &rhs) {
    data.reset(new char[strlen(rhs.data.get()) + 1]);
    strcpy(data.get(), rhs.data.get());
    return *this;
  }

  SString(SString &&rhs) noexcept = default;

  SString &operator=(SString &&rhs) noexcept = default;

  ~SString() = default;

  std::unique_ptr<char[]> data;
};

int main() { return 0; }
