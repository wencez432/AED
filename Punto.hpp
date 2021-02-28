//Clase interfaz privada

#include<cmath>

class Punto{
private:
	int x, y;

public:
	Punto(int X, int Y){
		x = X;
		y = Y;
	}
	Punto(){
		x = y = 0;
	}
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	double dist(Punto);
};

int Punto::getX(){
	return x;
}

int Punto::getY(){
	return y;
}

void Punto::setX(int X){
	x = X;
}

void Punto::setY(int Y){
	y = Y;
}

double Punto::dist(Punto p){
	int x1, y1, x2, y2;
	x1 = x;
	y1 = y;
	x2 = p.getX();
	y2 = p.getY();
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}