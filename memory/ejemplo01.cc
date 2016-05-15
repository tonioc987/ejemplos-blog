#include <cstdio>
#include <memory>
#include "mi_objecto.h"

int main() {
  MiObjeto *o = new MiObjeto("uno");
  std::unique_ptr<MiObjeto> up(new MiObjeto("dos"));
  return 0;
}

