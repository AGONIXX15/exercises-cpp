#include <iostream>

template <int N> struct Factorial {
  static constexpr int value = N * Factorial<N - 1>::value;
};

template <> struct Factorial<1> {
  static constexpr int value = 1;
};

template <typename T>
concept Addable = requires(T a, T b) {
  { a + b } -> std::is_convertible_v<T>;
};

template <Addable T> T suma(T a, T b) { return a + b; }

int main() {

  std::cout << suma('0', '1') << '\n';
  return 0;
}
