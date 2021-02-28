#include<iostream>

using namespace std;

int null = NULL;

class Nodo{
    public:
    int elemento;
    Nodo* siguiente;

    Nodo(int x){
        elemento = x;
        siguiente = NULL;
    }
};

class Bicola{
    private:
    Nodo *inicio, *fin;

    public:
    Bicola(){
        inicio = fin = NULL;
    }

    void insertarFin(int x){
        Nodo* nuevo = new Nodo(x);
        if(vacio()){
            inicio = nuevo;
        }
        else{
            fin->siguiente = nuevo;
        }
        fin = nuevo;
    }

    void insertarInicio(int x){
        Nodo* nuevo = new Nodo(x);
        if(vacio()){
            fin = nuevo;
        }
        else{
            nuevo->siguiente = inicio;
        }
        inicio = nuevo;
    }

    int quitarInicio(){
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

    int quitarFin(){
        if(vacio()){
            cout << "Cola vacia, no se puede extraer.\n";
            return -1;
        }
        else{
            cout << "Se elimino de la memoria el nodo: " << fin;
            int x = (fin->elemento);
            Nodo* n = fin;
            Nodo* a = inicio;
            while(a->siguiente != fin){
                a = a->siguiente;
            }
            fin = a;
            fin->siguiente = NULL;
            if(fin == NULL)
                inicio = NULL;
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
            return null;
        }
        else
            return inicio->elemento;
    }

    int getFinElemento(){
        if(vacio()){
            cout << "Cola vacia: ";
            return null;
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

void mostrar(Bicola &cola){
    int x;
    cout << "\nElementos de la Cola:\n";
    while (!cola.vacio()){
        cout << "Direccion frente: " << cola.getInicio() << " . Elemento frente: " << cola.getInicioElemento() << endl;
        cout << "Direccion final: " << cola.getFin() << " . Elemento final: " << cola.getFinElemento() << endl;
        x = cola.quitarInicio();
        cout << " . " << x << endl;
    }
    cout << "Direccion frente: " << cola.getInicio() << " . Elemento frente: " << cola.getInicioElemento() << endl;
    cout << "Direccion final: " << cola.getFin() << " . Elemento final: " << cola.getFinElemento() << endl;
}

void llenar(Bicola &cola){
    int x, e;
    cout << "Cuantos elementos desea ingresar: ";
    cin >> x;

    while(x--){
        cout << "Ingrese el elemento: ";
        cin >> e;
        cola.insertarFin(e);
        cout << "Direccion frente: " << cola.getInicio() << " . Elemento frente: " << cola.getInicioElemento() << endl;
        cout << "Direccion final: " << cola.getFin() << " . Elemento final: " << cola.getFinElemento() << endl;
    }
}

int main(int argc, char const *argv[]){
    Bicola bicola;
    mostrar(bicola);
    bicola.insertarFin(1);
    bicola.insertarFin(2);
    bicola.insertarFin(3);
    llenar(bicola);
    bicola.insertarInicio(7);
    bicola.quitarFin();
    mostrar(bicola);
    return 0;
}