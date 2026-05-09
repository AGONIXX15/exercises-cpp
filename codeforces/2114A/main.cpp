#include <iostream>
#include <math.h>
#include <string>

int main() {

  int n;
  std::cin >> n;
  std::string line;
  for(int i = 0; i < n; ++i){
    std::cin >> line; 
    int year = std::stoi(line);
    int root = std::sqrt(year);
    if(root * root != year){
      std::cout << "-1" << std::endl;
      continue;
    }

    std::cout << 0 << " " << root << std::endl;

  }
  return 0;
}
