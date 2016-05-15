#include <cstdio>
#include <memory>
#include "mi_objecto.h"

int main() {
  MiObjeto *o = new MiObjeto("uno");
  std::unique_ptr<MiObjeto> up(new MiObjeto("dos"));
  return 0;
}

/*
$ g++ --std=c++11 ejemplo01.cc 
$ ./a.out 
Constructor con un argumento: uno
Constructor con un argumento: dos
Destructor: dos.

*/

