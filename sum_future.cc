#include <iostream>
#include <future>
#include <algorithm>

using namespace std;

long parallel_sum(long * array, unsigned long length) {
  unsigned long const num_threads = thread::hardware_concurrency();
  unsigned long const block_size = length / num_threads;
  vector<future<long>> results(num_threads-1);
  long * block_start = array;

  for(unsigned long i = 0; i < num_threads - 1; 
      ++i, block_start+=block_size) {
    // lanzando tareas asincronas
    results[i] = async(launch::async, accumulate<long *, long>, 
                  block_start, block_start+block_size, 0L);
  }
  long result = accumulate(block_start, array + length, 0L);
  // recuperando resultados de las tareas asincronas
  for_each(results.begin(), results.end(), 
    [&result](future<long> &ft){result+=ft.get();});
  return result;
}

int main() {
  #define N_ELEMENTS 100000000UL
  long * values = new long[N_ELEMENTS];
  iota(values, values+N_ELEMENTS, 1);
  auto start = chrono::high_resolution_clock::now();
  long result = parallel_sum(values, N_ELEMENTS);
  auto stop = chrono::high_resolution_clock::now();
  cout << "resultado= " << result << endl;
  cout << "tiempo= " << 
    chrono::duration_cast<chrono::milliseconds>(stop-start).
      count() << " ms" << endl;
}

