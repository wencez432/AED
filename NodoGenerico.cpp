//Interfaz privada nodo generico

template <typename T>
class NodoGenerico{
    private:
    T dato;
    NodoGenerico<T>* enlace;

    public:
    NodoGenerico(T t){
        dato = t;
        enlace = 0;
    }

    NodoGenerico(T p, NodoGenerico<T>* n){
        dato = p;
        enlace = n;
    }

    T getDato(){
        return dato;
    }

    NodoGenerico<T>* getEnlace(){
        return enlace;
    }

    void setEnlace(NodoGenerico<T>* sgte){
        enlace = sgte;
    }
};