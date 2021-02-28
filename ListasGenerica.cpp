//Interfaz publica
//lista generica

#include"NodoGenerico.cpp"
#include<iostream>

using namespace std;

int main(){
    NodoGenerico<string>* nodo1;
    NodoGenerico<string>* nodo2;
    NodoGenerico<string>* nodo3;
    NodoGenerico<string>* nodo4;

    nodo1 = new NodoGenerico<string>("Juan Pablo");
    nodo2 = new NodoGenerico<string>("Rosa", nodo1);
    nodo3 = new NodoGenerico<string>("Benito", nodo2);
    nodo4 = new NodoGenerico<string>("Guadalupe", nodo3);

    //Mostrando direcciones de los nodos
    cout << "direccion1 = " << nodo1 << endl;
    cout << "direccion2 = " << nodo2 << endl;
    cout << "direccion3 = " << nodo3 << endl;
    cout << "direccion4 = " << nodo4 << endl << endl;

    //mostrar el dato de los nodos
    cout << "dato1 = " << nodo1->getDato() << endl;
    cout << "dato2 = " << nodo2->getDato() << endl;
    cout << "dato3 = " << nodo3->getDato() << endl;
    cout << "dato4 = " << nodo4->getDato() << endl << endl;

    //Mostrar enlace de los nodos
    cout << "enlace1 = " << nodo1->getEnlace()<<endl;
    cout << "enlace2 = " << nodo2->getEnlace()<<endl;
    cout << "enlace3 = " << nodo3->getEnlace()<<endl;
    cout << "enlace4 = " << nodo4->getEnlace()<<endl<<endl;

    //Poner enlace a un nodo
    nodo1->setEnlace(nodo4);

    //Mostrar enlace de los nodos
    cout << "enlace1 = " << nodo1->getEnlace()<<endl;
    cout << "enlace2 = " << nodo2->getEnlace()<<endl;
    cout << "enlace3 = " << nodo3->getEnlace()<<endl;
    cout << "enlace4 = " << nodo4->getEnlace()<<endl<<endl;
    return 0;
}