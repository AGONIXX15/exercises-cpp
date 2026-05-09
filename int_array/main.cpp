#include <iostream>
#include <cstdint>

// values 0,1,2,3 can save till 16 values

uint32_t introduce(int value, uint32_t arr, int pos) {

  int offset = pos * 2;
  int mask = 3 << offset;

  arr &= ~mask;

  arr |= (3 & value) << offset;
  return arr;
}

uint32_t get_value(int pos, uint32_t arr) {
  int offset = pos * 2;
  uint32_t mask = 3 << offset;

  return (arr & mask) >> offset;
}

int main() {

  int arr = 0;
  for(size_t i = 0; i < 16; ++i) {
    arr = introduce(2,arr,i);
  }

  std::cout << get_value(15,arr) << '\n';
  return 0;
}
