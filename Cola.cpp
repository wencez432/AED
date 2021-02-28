#include<iostream>

using namespace std;

class Nodo{
    public:
    int elemento;
    Nodo* siguiente;

    Nodo(int x){
        elemento = x;
        siguiente = NULL;
    }
};

class Cola{
    private:
    Nodo *inicio, *fin;

    public:
    Cola(){
        inicio = fin = NULL;
    }

    void insertar(int x){
        Nodo* nuevo = new Nodo(x);
        if(vacio()){
            inicio = nuevo;
        }
        else{
            fin->siguiente = nuevo;
        }
        fin = nuevo;
    }

    int quitar(){
        if(vacio()){
            cout << "Cola vacia, no se puede extraer.\n";
            return -1;
        }
        else{
            cout << "Se elimino de la memoria el nodo: " << inicio;
            int x = (inicio->elemento);
            Nodo* n = inicio;
            inicio = (inicio->siguiente);
            if(inicio == NULL)
                fin = NULL;
            delete n;
            return x;
        }
    }

    Nodo* getInicio(){
        return inicio;
    }

    Nodo* getFin(){
        return fin;
    }

    int getInicioElemento(){
        if(vacio()){
            cout << "Cola vacia: ";
            return NULL;
        }
        else
            return inicio->elemento;
    }

    int getFinElemento(){
        if(vacio()){
            cout << "Cola vacia: ";
            return NULL;
        }
        else
            return fin->elemento;
    }

    bool vacio(){
        if(inicio == NULL)
            inicio = fin = NULL;
        return inicio == NULL;
    }
};

void mostrar(Cola &cola){
    int x;
    cout << "\nElementos de la Cola:\n";
    while (!cola.vacio()){
        cout << "Direccion frente: " << cola.getInicio() << " . Elemento frente: " << cola.getInicioElemento() << endl;
        cout << "Direccion final: " << cola.getFin() << " . Elemento final: " << cola.getFinElemento() << endl;
        x = cola.quitar();
        cout << " . " << x << endl;
    }
    cout << "Direccion frente: " << cola.getInicio() << " . Elemento frente: " << cola.getInicioElemento() << endl;
    cout << "Direccion final: " << cola.getFin() << " . Elemento final: " << cola.getFinElemento() << endl;
}

void llenar(Cola &cola){
    int x, e;
    cout << "Cuantos elementos desea ingresar: ";
    cin >> x;

    while(x--){
        cout << "Ingrese el elemento: ";
        cin >> e;
        cola.insertar(e);
        cout << "Direccion frente: " << cola.getInicio() << " . Elemento frente: " << cola.getInicioElemento() << endl;
        cout << "Direccion final: " << cola.getFin() << " . Elemento final: " << cola.getFinElemento() << endl;
    }
}

int main(int argc, char const *argv[]){
    Cola cola;
    mostrar(cola);
    cola.insertar(1);
    cola.insertar(2);
    cola.insertar(3);
    llenar(cola);
    mostrar(cola);
    return 0;
}
