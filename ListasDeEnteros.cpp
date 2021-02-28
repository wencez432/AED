//Interfaz publica
//lista de enteros

#include"Nodo.cpp"
#include<iostream>

using namespace std;

int main(){
    Nodo* nodo1;
    Nodo* nodo2;
    Nodo* nodo3;
    Nodo* nodo4;

    nodo1 = new Nodo(10);
    nodo2 = new Nodo(20, nodo1);
    nodo3 = new Nodo(30, nodo2);
    nodo4 = new Nodo (40, nodo3);

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