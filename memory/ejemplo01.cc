#include <cstdio>
#include <memory>
#include "mi_clase.h"

int main() {
  MiClase *o = new MiClase("uno");
  std::unique_ptr<MiClase> up(new MiClase("dos"));
  return 0;
}

/*
$ g++ --std=c++11 ejemplo01.cc 
$ ./a.out 
Constructor con un argumento: uno
Constructor con un argumento: dos
Destructor: dos.

*/

