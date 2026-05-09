#include <iostream>

int main(){
  int x = 5;
  int *y = &x;
  int** z = &y;
  std::cout << &z << std::endl;
  std::cout << z << " == " << &y << std::endl;
  std::cout << *z << " == " << y << std::endl;;
  std::cout << **z << " == " << x << std::endl;;
}
