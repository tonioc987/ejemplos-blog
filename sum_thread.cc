#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

void thread_sum(long * start, long * end, long &result) {
  result = accumulate(start, end, 0L);
}

long parallel_sum(long * array, unsigned long length) {
  // variables para calcular cuantos elementos sumara cada hilo
  unsigned long const num_threads=thread::hardware_concurrency();
  unsigned long const block_size = length / num_threads;
  vector<long> results(num_threads);
  // n-1 hilos, porque el hilo actual sumara tambien un bloque
  vector<thread> threads(num_threads-1);
  long * block_start = array;

  for(unsigned long i = 0; i < num_threads - 1; 
      ++i, block_start+=block_size) {
    // lanzando n-1 hilos
    threads[i] = thread(thread_sum, block_start, 
                  block_start+block_size, ref(results[i]));
  }
  // el ultimo bloque es sumado por el hilo principal
  thread_sum(block_start, array + length, results[num_threads-1]);
  // esperando por todos los hilos
  for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
  // resultado final
  return accumulate(results.begin(), results.end(), 0L);
}

int main() {
  #define N_ELEMENTS 100000000UL
  long * values = new long[N_ELEMENTS];
  iota(values, values+N_ELEMENTS, 1);
  auto start = chrono::high_resolution_clock::now();
  long result = parallel_sum(values, N_ELEMENTS);
  auto stop = chrono::high_resolution_clock::now();
  cout << "resultado= " << result << endl;
  cout << "hilos=" << thread::hardware_concurrency() << endl;
  cout << "tiempo= " << 
    chrono::duration_cast<chrono::milliseconds>(stop-start).
      count() << " ms" << endl;
}

