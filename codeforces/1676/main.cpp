#include <iostream>

int main() {
  
  int n;
  std::cin >> n;
  for(int i = 0; i < n; ++i) {
    char a,b,c,d,e,f;
    std::cin >> a >> b >> c >> d >> e >> f;
    if(int(a) + int(b) + int(c) == int(d) + int(e) + int(f)){
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO";
    }

  }
}
