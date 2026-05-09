#include <iostream>

template <int N>
struct Factorial {
  static constexpr int value = N*Factorial<N-1>::value;
};

template<>
struct Factorial<1> {
  static constexpr int value = 1;
};

template<>
struct Factorial<0> {
  static constexpr int value = 0;
};

int main() {
  
  std::cout << Factorial<3>::value << '\n';
  return 0;
}
