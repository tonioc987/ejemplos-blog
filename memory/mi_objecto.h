#ifndef MI_OBJECTO_
#define MI_OBJECTO_

class MiObjeto {
 public:
  MiObjeto() {
    printf("Constructor sin argumentos\n");
  }
 
  MiObjeto(std::string name) : name(name) {
    printf("Constructor con un argumento: %s\n", name.c_str());
  }
  
  MiObjeto(const MiObjeto &other) {
    name = other.name + " copy";
    printf("Constructor copia: %s\n", name.c_str());
  }
  
  MiObjeto &operator=(const MiObjeto &other) {
    name = other.name + " assigned";
    printf("Operador =: %s\n", name.c_str());
  }
  
  ~MiObjeto() {
    printf("Destructor: %s.\n", name.c_str());
  }
  
 private:
  std::string name;
};

#endif

