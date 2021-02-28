#include<iostream>
#include<iomanip>
#include <ctime>

using namespace std;

template <typename T>
class Nodo{
private:
    T dato;
    Nodo<T>* enlace;

public:
    Nodo(T t){
        dato = t;
        enlace = NULL;
    }

    Nodo(T p, Nodo<T>* n){
        dato = p;
        enlace = n;
    }

    T getDato(){
        return dato;
    }

    Nodo<T>* getEnlace(){
        return enlace;
    }

    void setDato(T d){
        dato = d;
    }

    void setEnlace(Nodo<T>* e){
        enlace = e;
    }
};

class Lista{
private:
    Nodo<int>* head;
    
public:
    Lista(){
        head = NULL;
    }

    void randomList(int n){
        int x, i = 0;
        do{
            x = rand() % 51;
            head = new Nodo<int>(x, head);
            i++;
        }while(i != n);
    }
    void crearLista();
    void printLista();
    void insertarCabezaLista(int d);
    void insertarUltimo(int d);
    void insertarLista(int dAnt, int d);
    void eliminar(int d);
    Nodo<int>* find(int d);
    Nodo<int>* getTail();
};

void Lista::crearLista(){
    int x;
    do{
        cout << "Ingrese dato(termina con -1): ";
        cin >> x;
        if(x != -1)
            head = new Nodo<int>(x, head);
    }while(x != -1);
}

void Lista::printLista(){
    Nodo<int>* n = head;
    int i = 1;
    while(n != NULL){
        cout << setw(8) << "Nodo" << setw(3) << to_string(i) << ": Direccion = " << n << setw(11) << ", Dato = " << setw(3) << n->getDato() << setw(13) << ", Enlace = "<< n->getEnlace() << endl;
        n = n->getEnlace();
        i++;
    }
}

void Lista::insertarCabezaLista(int d){
    //head = new Nodo<int>(d, head);
    Nodo<int>* nuevo;
    nuevo = new Nodo<int>(d);
    nuevo->setEnlace(head);
    head = nuevo;
}

void Lista::insertarUltimo(int d){
    Nodo<int>* tail = getTail();
    tail->setEnlace(new Nodo<int>(d));
}

void Lista::insertarLista(int dAnt, int d){
    Nodo<int>* nuevo;
    Nodo<int>* anterior;
    nuevo = new Nodo<int>(d);
    anterior = find(dAnt);
    if(anterior != NULL){
        nuevo->setEnlace(anterior->getEnlace());
        anterior->setEnlace(nuevo);
    }
}

void Lista::eliminar(int d){
    Nodo<int> *actual, *anterior;
    bool encontrado;
    actual = head;
    anterior = NULL;
    encontrado = false;
    
    while ((actual != NULL) && !encontrado){
        encontrado = (actual->getDato() == d);
        if(!encontrado){
            anterior = actual;
            actual = actual->getEnlace();
        }
    }
    if (actual != NULL){
        if (actual == head){
            head = actual->getEnlace();
        }
        else{
            anterior->setEnlace(actual->getEnlace());
        }
        delete actual;
    }
}

Nodo<int>* Lista::find(int d){
    Nodo<int>* i;
    for(i = head; i != NULL; i = i->getEnlace()){
        if(i->getDato() == d)
            return i;
    }
    return NULL;
}

Nodo<int>* Lista::getTail(){
    Nodo<int>* p = head;
    while (p->getEnlace() != NULL)
    {
        p = p->getEnlace();
    }
    return p;
}

int main(int argc, char const *argv[]){
    srand(time(NULL));

    Lista miLista;
    miLista.crearLista();
    //miLista.randomList(4);
    miLista.printLista();
    cout << "\n Insertando en la cabeza y en la cola \n";
    miLista.insertarCabezaLista(24);
    miLista.insertarUltimo(34);
    miLista.printLista();

    return 0;
}
