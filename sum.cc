#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

int main() {
  #define N_ELEMENTS 100000000UL
  long * values = new long[N_ELEMENTS];
  iota(values, values+N_ELEMENTS, 1);
  auto start = chrono::high_resolution_clock::now();
  long result = accumulate(values, values+N_ELEMENTS, 0L);
  auto stop = chrono::high_resolution_clock::now();
  cout << "result= " << result << endl;
  cout << "duration= " << 
    chrono::duration_cast<chrono::milliseconds>(stop-start).
      count() << " ms" << endl;
}

