#include <algorithm>
#include <print>
#include <format>
#include <iostream>


template <typename... Args>
auto print_values(Args... args) {
  ([](auto&&... xs) {
      ((std::cout << xs << " "),...);
      std::cout << '\n';
  }(args...));

}

int main() {
  std::println("hello world!");
  print_values(1,2,3,"string",1);

  return 0;
}
