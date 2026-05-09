#include <iostream>
#include <math.h>
#include <queue>


// 144
// 441
double sqrt(int x) {
  std::queue<int> q;
  x = x * x;
  while(x != 0) {
    q.push(x % 10);
    x /= 10;
  }

  int number = 0;
  while(!q.empty()) {
    number =  number * 10 + q.front();
    q.pop();
  }
  return std::sqrt(number);
}

int main() {
  
  std::cout << sqrt(12) << '\n';
  return 0;
}
