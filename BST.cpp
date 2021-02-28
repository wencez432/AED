#include<iostream>

using namespace std;

class Nodo{
public:
    int dato;
    Nodo *izq, *der;

    Nodo(){
        dato = NULL;
        izq = der = NULL;
    }
};

class BST{
public:
    Nodo* raiz;

    BST(){raiz = NULL;}
    bool vacio(){return raiz == NULL;}

//Insertar simple
    void insertar(int x){
        if(raiz == NULL){
            raiz = new Nodo;
            raiz->dato = x;
            return;
        }
        Nodo *nuevo = new Nodo, *r = raiz;
        nuevo->dato = x;
        while(r != NULL){
            if(x < r->dato){
                if(r->izq == NULL){
                    r->izq = nuevo;
                    break;
                }
                r = r->izq;
            }
            else if(x > r->dato){
                if(r->der == NULL){
                    r->der = nuevo;
                    break;
                }
                r = r->der;
            }
        }
    }

//Insertar recursibo
    //Funcion que inicia la recursibidad
    void insertaR(int x){
        if(raiz == NULL){
            raiz->dato = x;
            return;
        }
        insertarR(raiz, x);
    }

    //Funcion recursiba
    void insertarR(Nodo *r, int x){
        if(x < r->dato){
            if(r->izq == NULL){
                Nodo *nuevo = new Nodo;
                nuevo->dato = x;
                r->izq = nuevo;
                return;
            }
            insertarR(r->izq, x);
        }
        else{
            if(x > r->dato){
                if(r->der == NULL){
                    Nodo *nuevo = new Nodo;
                    nuevo->dato = x;
                    r->der = nuevo;
                    return;
                }
                insertarR(r->der, x);
            }
        }
    }

//Recorridos en profundidad
    //Preorden (R, I, D)
    void preOrden(Nodo *raiz){
        if(raiz != NULL){
            cout << raiz->dato << " ";
            preOrden(raiz->izq);
            preOrden(raiz->der);
        }
    }

    //Enorden (I, R, D)
    void enOrden(Nodo *raiz){
        if(raiz != NULL){
            enOrden(raiz->izq);
            cout << raiz->dato << " ";
            enOrden(raiz->der);
        }
    }

    //Postorden (I, D, R)
    void postOrden(Nodo *raiz){
        if(raiz != NULL){
            postOrden(raiz->izq);
            postOrden(raiz->der);
            cout << raiz->dato << " ";
        }
    }

//Recorrido en anchura
    void porAnchura(BST a){
        int nivel = 0, niveles = a.encontrarAltura(a.raiz) - 1;
        while(nivel <= niveles){
            verNivel(a.raiz, nivel);
            nivel++;
            cout << endl;
        }
    }

    void verNivel(Nodo *raiz, int n){
        if(raiz != NULL){
            if(n == 0)
                cout << raiz->dato << " ";
            else{
                verNivel(raiz->izq, n-1);
                verNivel(raiz->der, n-1);
            }
        }
    }

//Contar nodos del arbol
    int contarNodos(Nodo *raiz){
        int n=1;
        if(raiz->izq != NULL)
            n += contarNodos(raiz->izq);
        if(raiz->der != NULL)
            n += contarNodos(raiz->der);
        return n;
    }

//Calculando profundidada o altura
    int encontrarAltura(Nodo *raiz){
        if(raiz != NULL)
            return max(encontrarAltura(raiz->izq), encontrarAltura(raiz->der)) + 1;
    }

//Busqueda de un nodo
    Nodo* busqueda(Nodo *raiz, int datoB){
        Nodo *r = raiz, *rpta = NULL;
        while(r != NULL){
            if(r->dato == datoB){
                rpta = r;
                break;
            }
            if(datoB < r->dato)
                r = r->izq;
            else
                r = r->der;
        }
        return rpta;
    }

//Eliminar Nodo
    void borrarNodo(int datoAB){
        Nodo *r = raiz, *padre = NULL, *t;
        while(r != NULL){
            if(r->dato == datoAB)
                break;
            padre = r;
            if(datoAB < r->dato)
                r = r->izq;
            else
                r = r->der;
        }
        if(r == NULL){
            cout << "El dato no esta en el arbol" << endl;
            return;
        }
        int numHijos=0;
        if(r->izq != NULL)
            numHijos++;
        if(r->der != NULL)
            numHijos++;
        if(numHijos == 0)
            borrarNodoHoja(padre, r);
        else
            if(numHijos == 1)
                borrarNodoHijo1(padre, r);
            else
                borrarNodoHijo2I(r);
    }

    //Caso nodo hoja
    void borrarNodoHoja(Nodo *padre, Nodo *n){
        if(padre != NULL){
            if(padre->izq == n)
                padre->izq = NULL;
            else
                padre->der = NULL;
        }
        else
            raiz = NULL;
        delete n;
    }

    //Caso nodo con un hijo
    void borrarNodoHijo1(Nodo * padre, Nodo *n){
        if(padre != NULL){
            if(padre->izq == n){
                if(n->izq != NULL)
                    padre->izq = n->izq;
                else
                    padre->izq = n->der;
            }
            else{
                if(n->izq != NULL)
                    padre->der = n->izq;
                else
                    padre->der = n->der;
            }
        }
        else{
            if(n->izq != NULL)
                raiz = n->izq;
            else
                raiz = n->der;
        }
        delete n;
    }

    //Caso nodo con 2 hijos buscando reemplazo en subarbol izquierdo
    void borrarNodoHijo2I(Nodo *n){
        int d;
        Nodo *padre = n, *r = n->izq;
        while(r->der != NULL){
            padre = r;
            r = r->der;
        }
        d = r->dato;
        if(r->izq != NULL)
            borrarNodoHijo1(padre, r);
        else
            borrarNodoHoja(padre, r);
        n->dato = d;
    }

    //Caso nodo con 2 hijos buscando reemplazo en subarbol derecho
    void borrarNodoHijo2D(Nodo *n){
        int d;
        Nodo *padre = n, *r = n->der;
        while(r->izq != NULL){
            padre = r;
            r = r->izq;
        }
        d = r->dato;
        if(r->der != NULL)
            borrarNodoHijo1(padre, r);
        else
            borrarNodoHoja(padre, r);
        n->dato = d;
    }
};

void llenarBST(BST &a){
    int n, dato;
    cout << "Cuantos nodos desea insertar: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Dato " << i << ": ";
        cin >> dato;
        a.insertar(dato);
    }
}

int main(int argc, char const *argv[]){
    BST a;
    llenarBST(a);
    cout << "\nMostrando en Preorden:\n";
    a.preOrden(a.raiz);
    cout << "\nMostrando en Anchura:\n";
    a.porAnchura(a);
    int e;
    cout << "Ingrese dato a borrar: ";  cin >> e;
    a.borrarNodo(e);
    cout << "\nMostrando en Preorden:\n";
    a.preOrden(a.raiz);
    cout << "\nMostrando en Anchura:\n";
    a.porAnchura(a);
    return 0;
}
