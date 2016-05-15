#ifndef MI_CLASE_
#define MI_CLASE_

class MiClase {
 public:
  MiClase() {
    printf("Constructor sin argumentos\n");
  }
 
  MiClase(std::string name) : name(name) {
    printf("Constructor con un argumento: %s\n", name.c_str());
  }
  
  MiClase(const MiClase &other) {
    name = other.name + " copy";
    printf("Constructor copia: %s\n", name.c_str());
  }
  
  MiClase &operator=(const MiClase &other) {
    name = other.name + " assigned";
    printf("Operador =: %s\n", name.c_str());
  }
  
  ~MiClase() {
    printf("Destructor: %s.\n", name.c_str());
  }
  
 private:
  std::string name;
};

#endif

