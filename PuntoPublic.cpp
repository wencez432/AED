//Clase interfaz publica

#include "Punto.hpp"
#include<iostream>

using namespace std;

int main(){
	Punto p1(2,4);
	Punto p2(6,7);
	Punto p3;
	cout << p1.getX() << "\n";
	cout << p1.getY() << "\n";
	cout << "Distancia de P1 a P2: " << p2.dist(p1) << endl;
	cout << "Distancia de P1 al origen: " << p3.dist(p1) << endl;
	return 0;
}