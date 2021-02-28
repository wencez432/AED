#include <iostream>
#include <string>

using namespace std;

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

    void agregarArco(nodo* aux, nodo* aux2, arco* nuevo){
        arco* q;
        if(aux->ady == NULL){
            aux->ady = nuevo;
            nuevo->destino = aux2;
            cout << "1er arco del nodo" << aux->nombre << endl;
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
                    p->borrarTodosArcos(aux);
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

void completarArcos(nodo *p){
    int t;
    cout << "Cuantos arcos desea ingresar: ";
    cin >> t;
    while(t--){
        p->insertarArco();
    }
}

int main(int argc, char const *argv[]){
    nodo* p = new nodo;
    //Insertando nodos
    completarNodos(p);
    cout << "Mostrando grafo:\n";
    p->mostrarGrafo();
    //Insertar arcos
    completarArcos(p);
    cout << "Mostrando grafo:\n";
    p->mostrarGrafo();
    //Borrando nodos
    p->eliminarNodo();
    cout << "Mostrando grafo:\n";
    p->mostrarGrafo();
    return 0;
}
