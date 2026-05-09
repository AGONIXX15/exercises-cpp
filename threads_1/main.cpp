#include <iostream>
#include <thread>
#include <atomic>


std::atomic<int> counter = 0;


void task(int i) {

  for(size_t j = 0; j < 100; ++j) {
    std::cout << "in task " << i << "doing iteration " << j << std::endl;
    counter++;
  }
}

int main() {
  std::thread t1(task,0);
  std::thread t2(task,1);

  t1.join();
  t2.join();

  std::cout << "counter value at the end " << counter << std::endl;

  return 0;
}
