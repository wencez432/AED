#include<iostream>

using namespace std;

typedef string Tipo;

class Nodo{
private:
    Tipo dato;
    Nodo *izq, *der;

public:
    Nodo(Tipo x){
        dato = x;
        izq = der = NULL;
    }

    Nodo(Nodo* nodoIzq, Tipo x, Nodo* nodoDer){
        dato = x;
        izq = nodoIzq;
        der = nodoDer;
    }

    Tipo getValor(){return dato;}
    Nodo* subArbolIzq(){return izq;}
    Nodo* subArbolDer(){return der;}
    void setValor(Tipo x){dato = x;}
    void setNodoIzq(Nodo* n){izq = n;}
    void setNodoDer(Nodo* n){der = n;}
};

class ArbolBinario{
private:
    Nodo* raiz;

public:
    ArbolBinario(){raiz = NULL;}
    bool vacio(){return raiz == NULL;}

    Nodo* getRaiz(){
        if(vacio())
            cout << "Arbol vacio\n";
        else
            return raiz;
    }

    Nodo* hijoIzq(){
        if(vacio())
            cout << "Arbol vacio\n";
        else
            return raiz->subArbolIzq();
    }

    Nodo* hijoDer(){
        if(vacio())
            cout << "Arbol vacio\n";
        else
            return raiz->subArbolDer();
    }

    Nodo* nuevoArbol(Nodo* nodoIzq, Tipo d, Nodo* nodoDer){return new Nodo(nodoIzq, d, nodoDer);}
    void setRaiz(Nodo* r){raiz = r;}
    Nodo* getRaiz(){return raiz;}
};

int main(int argc, char const *argv[]){
    ArbolBinario a;
    Tipo e = a.getRaiz()->getValor();
    return 0;
}
