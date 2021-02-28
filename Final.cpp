#include <iostream>
#include <string>

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
                borrarNodoHijo2I(padre, r);
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
    void borrarNodoHijo1(Nodo *padre, Nodo *n){
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
    void borrarNodoHijo2I(Nodo *Padre, Nodo *n){
        Nodo *padre = n, *r = n->izq;
        while(r->der != NULL){
            padre = r;
            r = r->der;
        }
        if(r->izq != NULL){
            if(padre->izq == r)
                padre->izq = r->izq;
            else
                padre->der = r->izq;
        }
        else{
            if(padre->izq == r)
                padre->izq = NULL;
            else
                padre->der = NULL;
        }
        if(Padre != NULL){
            if(Padre->izq == n)
                Padre->izq = r;
            else
                Padre->der = r;
        }
        else{
            raiz = r;
        }
        r->izq = n->izq;
        r->der = n->der;
        delete n;
    }

    //Caso nodo con 2 hijos buscando reemplazo en subarbol derecho
    void borrarNodoHijo2D(Nodo *Padre, Nodo *n){
        Nodo *padre = n, *r = n->der;
        while(r->izq != NULL){
            padre = r;
            r = r->izq;
        }
        if(r->der != NULL){
            if(padre->izq == r)
                padre->izq = r->der;
            else
                padre->der = r->der;
        }
        else{
            if(padre->izq == r)
                padre->izq = NULL;
            else
                padre->der = NULL;
        }
        if(Padre != NULL){
            if(Padre->izq == n)
                Padre->izq = r;
            else
                Padre->der = r;
        }
        else{
            raiz = r;
        }
        r->izq = n->izq;
        r->der = n->der;
        delete n;
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

class nodo{
    public:
    class arco{
        public:
        nodo* destino;
        arco* sgte;
    };
    string nombre;
    nodo* sgte;
    arco* ady;
    nodo* p;

    void insertarNodo(){
        nodo *t, *nuevo = new nodo;
        cout << "Ingrese el nombre: ";
        cin >> nuevo->nombre;
        nuevo->sgte = NULL;
        nuevo->ady = NULL;
        if(p == NULL){
            p = nuevo;
            cout << "Primer nodo del directorio\n";
        }
        else{
            t = p;
            while(t->sgte != NULL)
                t = t->sgte;
            t->sgte = nuevo;
            cout << "Nodo ingresado\n";
        }
    }

    //Inserta nodos de valor entero al grafo
    void insertarNodoInt(int d){
        nodo *t, *nuevo = new nodo;
        nuevo->nombre = to_string(d);
        nuevo->sgte = NULL;
        nuevo->ady = NULL;
        if(p == NULL){
            p = nuevo;
        }
        else{
            t = p;
            while(t->sgte != NULL)
                t = t->sgte;
            t->sgte = nuevo;
        }
    }

    void mostrarGrafo(){
        nodo* t = p;
        arco* ar;
        cout << "Nodo\t|\tLista de adyacencia\n";
        while(t != NULL){
            cout << t->nombre << "\t|";
            if(t->ady != NULL){
                ar = t->ady;
                while(ar != NULL){
                    cout << " " << ar->destino->nombre;
                    ar = ar->sgte;
                }
            }
            t = t->sgte;
            cout << endl;
        }
    }

    void insertarArco(){
        string ini, fin;
        arco* nuevo = new arco();
        nodo *aux = p, *aux2 = p;
        if(p == NULL){
            cout << "Gafo vacio\n";
            return;
        }
        nuevo->sgte = NULL;
        cout << "Ingrese el nombre del nodo inicio: ";
        cin >> ini;
        cout << "Ingrese el nombre del nodo final: ";
        cin >> fin;
        while(aux2 != NULL){
            if(aux2->nombre == fin)
                break;
            aux2 = aux2->sgte;
        }
        while(aux != NULL){
            if(aux->nombre == ini){
                agregarArco(aux, aux2, nuevo);
                return;
            }
            aux = aux->sgte;
        }
    }

    void insertarArcoIntInt(int i, int f){
        string ini, fin;
        arco* nuevo = new arco();
        nodo *aux = p, *aux2 = p;
        if(p == NULL){
            cout << "Gafo vacio\n";
            return;
        }
        nuevo->sgte = NULL;
        ini = to_string(i);
        fin = to_string(f);
        while(aux2 != NULL){
            if(aux2->nombre == fin)
                break;
            aux2 = aux2->sgte;
        }
        while(aux != NULL){
            if(aux->nombre == ini){
                agregarArcoSin(aux, aux2, nuevo);
                return;
            }
            aux = aux->sgte;
        }
    }

    void agregarArcoSin(nodo* aux, nodo* aux2, arco* nuevo){
        arco* q;
        if(aux->ady == NULL){
            aux->ady = nuevo;
            nuevo->destino = aux2;
        }
        else{
            q = aux->ady;
            while(q->sgte != NULL)
                q = q->sgte;
            q->sgte = nuevo;
            nuevo->destino = aux2;
        }
    }

    void agregarArco(nodo* aux, nodo* aux2, arco* nuevo){
        arco* q;
        if(aux->ady == NULL){
            aux->ady = nuevo;
            nuevo->destino = aux2;
            cout << "1er arco del nodo " << aux->nombre << endl;
        }
        else{
            q = aux->ady;
            while(q->sgte != NULL)
                q = q->sgte;
            q->sgte = nuevo;
            nuevo->destino = aux2;
            cout << "Arco agregado\n";
        }
    }

    void eliminarNodo(){
        string nom;
        nodo *aux = p, *ant;
        if(p == NULL){
            cout << "Grafo vacio\n";
            return;
        }
        cout << "Ingrese el nombre del nodo a borrar: ";
        cin >> nom;
        while(aux != NULL){
            if(aux->nombre == nom){
                if(aux->ady != NULL)
                    borrarTodosArcos(aux);
                eliminarReferencias(aux);
                if(aux == p){
                    p = p->sgte;
                    delete(aux);
                    cout << "Nodo cabeza eliminado\n";
                    return;
                }
                else{
                    ant->sgte = aux->sgte;
                    delete(aux);
                    cout << "Nodo eliminado\n";
                    return;
                }
            }
            else{
                ant = aux;
                aux = aux->sgte;
            }
        }
    }

    void borrarTodosArcos(nodo* aux){
        arco *q = aux->ady, *r;
        while(q->sgte != NULL){
            r = q;
            q = q->sgte;
            delete(r);
        }
    }

    void eliminarReferencias(nodo *n){
        nodo *tem = p;
        while(tem != NULL){
            if(tem->nombre != n->nombre){
                eliminarArcoA(tem->nombre, n->nombre);
            }
            tem = tem->sgte;
        }
    }

    void eliminarArcoA(string ini, string fin){
        nodo *aux = p, *aux2 = p;
        arco *q, *r;
        while(aux2 != NULL){
            if(aux2->nombre == fin)
                break;
            else
                aux2 = aux2->sgte;
        }
        while(aux != NULL){
            if(aux->nombre == ini){
                q = aux->ady;
                while(q != NULL){
                    if(q->destino == aux2){
                        if(q == aux->ady)
                            aux->ady = aux->ady->sgte;
                        else
                            r->sgte = q->sgte;
                        delete(q);
                        return;
                    }
                    r = q;
                    q = q->sgte;
                }
            }
            aux = aux->sgte;
        }
    }

    void mostrarArcos(){
        nodo* aux = p;
        arco* ar;
        string nom;
        cout << "Ingrese el nombre del nodo: ";
        cin >> nom;
        while(aux != NULL){
            if(aux->nombre == nom){
                if(aux->ady == NULL){
                    cout << "El nodo no contiene arcos\n";
                    return;
                }
                else{
                    cout << "Nodo\t|\tLista de adyacencia\n";
                    cout << aux->nombre << "\t|";
                    ar = aux->ady;
                    while(ar != NULL){
                        cout << ar->destino->nombre << " ";
                        ar = ar->sgte;
                    }
                    cout << endl;
                    return;
                }
            }
            else
                aux = aux->sgte;
        }
    }

    void eliminarArco(){
        string ini, fin;
        nodo *aux = p, *aux2 = p;
        arco *q, *r;
        cout << "Ingrese el nombre del nodo inicio: ";
        cin >> ini;
        cout << "Ingrese el nombre del nodo final: ";
        cin >> fin;
        while(aux2 != NULL){
            if(aux2->nombre == fin)
                break;
            else
                aux2 = aux2->sgte;
        }
        while(aux != NULL){
            if(aux->nombre == ini){
                q = aux->ady;
                while(q != NULL){
                    if(q->destino == aux2){
                        if(q == aux->ady)
                            aux->ady = aux->ady->sgte;
                        else
                            r->sgte = q->sgte;
                        delete(q);
                        cout << "Arco " << aux->nombre << "----->" << aux2->nombre << " Eliminado\n";
                        return;
                    }
                    r = q;
                    q = q->sgte;
                }
            }
            aux = aux->sgte;
        }
    }
};

void completarNodos(nodo* p){
    int t;
    cout << "Cuantos nodos desea ingresar: ";
    cin >> t;
    while(t--){
        p->insertarNodo();
    }
}

//Vita nodos del arbol y los inserta al grafo
void verNivelP(Nodo *raiz, int n, nodo* p){
    if(raiz != NULL){
        if(n == 0)
            p->insertarNodoInt(raiz->dato);
        else{
            verNivelP(raiz->izq, n-1, p);
            verNivelP(raiz->der, n-1, p);
        }
    }
}

//Recorre arbol nivel por nivel desde abajo hacia arriba
void completarNodosGrafoArbol(nodo* p, BST &a){
    int niveles = a.encontrarAltura(a.raiz) - 1;
    int nivel = niveles;
        while(nivel >= 0){
            verNivelP(a.raiz, nivel, p);
            nivel--;
        }
}

void completarArcos(nodo *p){
    int t;
    cout << "Cuantos arcos desea ingresar: ";
    cin >> t;
    while(t--){
        p->insertarArco();
    }
}

//Recorrer arbol e insertar arcos al grafo
void completarArcosGrafoArbol(nodo *p, BST &a){
    nodo* t = p->p;
    Nodo* n;
    while(t != NULL){
        n = a.raiz;
        while(n->dato != stoi(t->nombre)){
            p->insertarArcoIntInt(stoi(t->nombre), n->dato);
            if(stoi(t->nombre) < n->dato)
                n = n->izq;
            else
                n = n->der;
        }
        t = t->sgte;
    }
}

int main(int argc, char const *argv[]){
//Creando arbol binario llenando y mostrando en anchura
    BST a;
    llenarBST(a);
    cout << "\nMostrando en Anchura:\n";
    a.porAnchura(a);
//Creando grafo
    nodo* p = new nodo;
    //Insertando nodos del arbol al grafo
    completarNodosGrafoArbol(p, a);
    //Completar arcos del grafo
    completarArcosGrafoArbol(p, a);
    //Mostrando grafo
    cout << "Mostrando grafo:\n";
    p->mostrarGrafo();
    return 0;
}
