#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main(){
  for(int i = 0; i < 101; i += 10) {
    cout << "u are gay a " << i << "%" << '\n';
    this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  return 0;
}
