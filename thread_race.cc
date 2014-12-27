//  g++ -std=c++11 thread_race.cc -o thread_race -pthread
#include <iostream>
#include <thread>
#include <mutex>

int counter;

void increment() {
  for(int i=0; i<1000; ++i) {
    counter++;
  }
}

int main() {
  for(int i = 0; i < 1000; ++i) {
    counter = 0;
    std::thread t1 = std::thread(increment);
    std::thread t2 = std::thread(increment);
    t1.join(); t2.join();
    if(counter != 2000) {
      std::cout << i << ": " << counter << std::endl;
    }
  }
  return 0;
}
