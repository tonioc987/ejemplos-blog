#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  #define N_ELEMENTS 100000000UL
  long * values = new long[N_ELEMENTS];
  iota(values, values+N_ELEMENTS, 1);
  
  long result = accumulate(values, values+N_ELEMENTS, 0);
  cout << "resultado= " << result << endl;
  
  result = accumulate(values, values+N_ELEMENTS, 0L);
  cout << "resultado= " << result << endl;
}

