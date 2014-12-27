//  g++ -std=c++11 thread_mutex.cc -o thread_mutex -pthread
#include <iostream>
#include <thread>
#include <mutex>

int counter;
std::mutex mtx;

void increment() {
  for(int i=0; i<1000; ++i) {
    mtx.lock();
    counter++;
    mtx.unlock();
  }
}

int main() {
  auto start = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < 10000; ++i) {
    counter = 0;
    std::thread t1 = std::thread(increment);
    std::thread t2 = std::thread(increment);
    t1.join(); t2.join();
    if(counter != 2000) {
      std::cout << i << ": " << counter << std::endl;
    }
  }
  auto stop = std::chrono::high_resolution_clock::now();
  std::cout << "tiempo= " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).
      count() << " ms" << std::endl;
  return 0;
}
