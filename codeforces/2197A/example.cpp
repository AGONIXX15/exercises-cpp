#include <iostream>

int main() {
  int n = 100;
  for(int i = 1; i < n; i *= 2) {
    for(int j = 1; j < i; ++j) {
      std::cout << "hello world!" << '\n';
    }
  }
}
