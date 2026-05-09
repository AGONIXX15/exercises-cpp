#include <iostream>
#include <thread>
#include <chrono>

union Foo
{
  int x;
  long long y;
  char a;
  Foo(int x) : x{ x } {};
  void print() { std::cout << this->x << '\n'; }
};

int main() {

  Foo f = {65};
  std::cout << f.a << '\n'; // A
  return 0;
}
