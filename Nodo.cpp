//interfaz privada
//lista de enteros

class Nodo{
  private:
  int dato;
  Nodo* enlace;

  public:
  Nodo(int t){
      dato = t;
      enlace = 0; //0 es el puntero NULL en C++
  }

  Nodo(int p, Nodo* n){
    dato = p;
    enlace = n;
  }

  int getDato(){
    return dato;
  }

  Nodo* getEnlace(){
    return enlace;
  }

  void setEnlace(Nodo* sgte){
    enlace = sgte;
  }
};