
#include <iostream>
#include <unordered_map>

int fibo(int n) {
  
  int a = 0;
  int b = 1;
  int c;
  for(size_t i = 0; i < n; ++i) {
    c = a + b;
    a = b;
  }
  return c;
}

int fibo_rec(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  return fibo_rec(n-1) + fibo_rec(n-2);
}

int fibo_rec_memo(int n, std::unordered_map<int,int> dct ) {

}

int main() {

  std::cout << fibo(3) << '\n';
  std::cout << fibo_rec(3) << '\n';
  return 0;
}
