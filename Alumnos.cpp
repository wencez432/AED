#include <iostream>
//#include <cstring>
#include <string>
#include <locale>
#include <iomanip>

using namespace std;

struct Alumno{
	string Paterno;
	string Materno;
	string Nombre;
	int Nota;
};

Alumno alumnos[50];
int numAlumnos = 0;
string Paterno, Materno, Nombre;
int Nota;

void swap(Alumno &x, Alumno &y){
	Alumno t = x;
	x = y;
	y = t;
}

int compare(string s1, string s2){
	int l1 = s1.length(), l2 = s2.length();
	char cs1[l1], cs2[l2];
	for(int i = 0; i<l1; i++){
		cs1[i] = s1[i];
	}
	for(int i = 0; i<l2; i++){
		cs2[i] = s2[i];
	}
	int minl;
	char n[6] = "ÑNO";
	if(l1<l2)	minl = l1;
	else	minl = l2;
	for(int i=0; i<minl ; i++){
		if(cs1[i] != n[0] && cs2[i] != n[0]){
			if(cs1[i] < cs2[i])	return -1;
			else	if(cs1[i] > cs2[i])	return 1;
		}
		else{
			if(!(cs1[i] == n[0] && cs2[i] == n[0])){
				if(cs1[i] == n[0]){
					if(cs2[i] > n[1])	return -1;
					if(cs2[i] < n[2])	return 1;
				}
				if(cs2[i] == n[0]){
					if(cs1[i] > n[1])	return 1;
					if(cs1[i] < n[2])	return -1;
				}
			}
		}
	}
	if(l1 != l2){
		if(minl == l1)	return -1;
		else 	return 1;
	}
	else	return 0;
}

int LorG(Alumno a1, Alumno a2){
	int res1 = compare(a1.Paterno, a2.Paterno), res2 = compare(a1.Materno, a2.Materno), res3 = compare(a1.Nombre, a2.Nombre);
    bool flag = false;
    if(res1 != 0){
        if(res1 == -1)	flag = true;
    }
    else if(res2 != 0){
        if(res2 == -1)	flag = true;
    }
    else if(res3 != 0){
        if(res3 == -1)	flag = true;
    }
    else{
        if(a1.Nota < a2.Nota)	flag = true;
    }
    if(flag) return -1;
    else return 1;
}

void QuickSort(Alumno A[], int l, int h){
	int pivpos = (l+h)/2, i = l, j = h;
	Alumno piv = A[pivpos];
	while(i<=j){
		while(LorG(A[i],piv) == -1)	i++;
		while(LorG(A[j],piv) == 1)	j--;
		if(i<=j){
			swap(A[i],A[j]);
			i++;
			j--;
		}
	}
	if(l < j){
		QuickSort(A,l,j);
	}
	if(i < h){
		QuickSort(A,i,h);
	}
}

void PrintAlumnos(){
	cout << "\n";
	cout << setw(20) << "Apellido Paterno" << setw(20) << "Apellido Materno" << setw(20) << "Nombre" << setw(20) << "Nota";
	cout << "\n";
	for(int i=0; i<numAlumnos; i++){
		cout << setw(20) << alumnos[i].Paterno << setw(20) << alumnos[i].Materno << setw(20) << alumnos[i].Nombre << setw(20) << alumnos[i].Nota << "\n";
	}
	cout << "\nNúmero de alumnos: " << numAlumnos << "\n";
	cout << "\n";
}

void PedirDatos(){
	cout << "Ingrese nombre completo (PATERNO MATERNO NOMBRE): ";
	cin >> Paterno;	cin >> Materno;	cin >> Nombre;
	cout << "Ingrese Nota (0 a 20): ";
	cin >> Nota;
	for (auto & c: Paterno) c = toupper(c);
	for (auto & c: Materno) c = toupper(c);
	for (auto & c: Nombre) c = toupper(c);
}

int getAlumno(){
	int pos;
	for(int i=0; i<numAlumnos; i++){
		if(alumnos[i].Paterno == Paterno && alumnos[i].Materno == Materno && alumnos[i].Nombre == Nombre && alumnos[i].Nota == Nota){
			pos = i;
			break;
		}
	}
	return pos;
}

void IngresarAlumno(){
	PedirDatos();
	bool flag = false;
	for(int i=0; i<numAlumnos; i++){
		if(alumnos[i].Paterno == Paterno && alumnos[i].Materno == Materno && alumnos[i].Nombre == Nombre && alumnos[i].Nota == Nota){
			flag = true;
			break;
		}
	}
	if(!flag){
		alumnos[numAlumnos].Paterno = Paterno;
		alumnos[numAlumnos].Materno = Materno;
		alumnos[numAlumnos].Nombre = Nombre;
		alumnos[numAlumnos].Nota = Nota;
		numAlumnos++;
		if(numAlumnos > 1)	QuickSort(alumnos,0,numAlumnos-1);
		PrintAlumnos();
	}else{
		cout << "Alumno ingresado ya existe!!\n";
	}
}

void EliminarAlumno(){
	PedirDatos();
	int pos = getAlumno();
	for(int i = pos; i<numAlumnos; i++){
		alumnos[i] = alumnos[i+1];
	}
	numAlumnos--;
	PrintAlumnos();
}

int main(int argc, char const *argv[])
{
	int op;
	do{
		cout << "----------------------\n";
		cout << "|         Menu       |\n";
		cout << "| 1) Ingresar alumno |\n";
		cout << "| 2) Eliminar alumno |\n";
		cout << "| 3) Salir           |\n";
		cout << "----------------------\n\n";
		cout << "Elija opción: ";	cin >> op;
		switch(op){
			case 1: IngresarAlumno();	break;
			case 2: EliminarAlumno();	break;
			case 3: cout << "Hasta Pronto!!\n";	break;
			default: cout << "Opción invalida\n";
		}
	}while(op!=3);
	return 0;
}