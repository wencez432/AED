#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

struct Alumno
{
	string Paterno;
	string Materno;
	string Nombre;
	int Nota;
};

Alumno alumnos[50];
int numAlumnos = 0;

void swap(Alumno &x, Alumno &y){
	Alumno t = x;
	x = y;
	y = t;
}

int compare(string s1, string s2){
	char cs1[20], cs2[20];
	strcpy(cs1,s1.c_str());
	strcpy(cs2,s2.c_str());
	int res = strcmp(cs1,cs2);
	if(res < 0)	return -1;
	else	if(res > 0)	return 1;
			else return 0;
}

int LorG(Alumno a1, Alumno a2){
	int res1 = compare(a1.Paterno, a2.Paterno), res2 = compare(a1.Materno, a2.Materno), res3 = compare(a1.Nombre, a2.Nombre);
	if(res1 == -1)	return -1;
	else	if(res1 == 1)	return 1;
			else	if(res2 == -1)	return -1;
					else	if(res2 == 1)	return 1;
						else	if(res3 == -1)	return -1;
								else	if(res3 == 1)	return 1;
									else	if(a1.Nota < a2.Nota)	return -1;
											else	return 1;
}

/*
bool isL(string s1, string s2){
	char cs1[100], cs2[100];
	strcpy(cs1,s1.c_str());
	strcpy(cs2,s2.c_str());
	int res = strcmp(cs1,cs2);
	if(res < 0)	return true;
	else	return false;
}

bool isLower(Alumno a1, Alumno a2){
	string sn1, sn2;
	if(a1.Nota < 10){
		sn1 = "0" + to_string(a1.Nota);
	}else sn1 = to_string(a1.Nota);
	if(a2.Nota < 10){
		sn2 = "0" + to_string(a2.Nota);
	}else sn2 = to_string(a2.Nota);
	string al1 = a1.Paterno + a1.Materno + a1.Nombre + sn1;
	string al2 = a2.Paterno + a2.Materno + a2.Nombre + sn2;
	return isL(al1,al2);
}

bool isG(string s1, string s2){
	char cs1[100], cs2[100];
	strcpy(cs1,s1.c_str());
	strcpy(cs2,s2.c_str());
	int res = strcmp(cs1,cs2);
	if(res > 0)	return true;
	else	return false;
}

bool isGreater(Alumno a1, Alumno a2){
	string sn1, sn2;
	if(a1.Nota < 10){
		sn1 = "0" + to_string(a1.Nota);
	}else sn1 = to_string(a1.Nota);
	if(a2.Nota < 10){
		sn2 = "0" + to_string(a2.Nota);
	}else sn2 = to_string(a2.Nota);
	string al1 = a1.Paterno + a1.Materno + a1.Nombre + sn1;
	string al2 = a2.Paterno + a2.Materno + a2.Nombre + sn2;
	return isG(al1,al2);
}
*/

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

int getAlumno(string Paterno, string Materno, string Nombre, int Nota){
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
	string Paterno, Materno, Nombre, alumno;
	int Nota;
	cout << "Ingrese nombre completo (PATERNO MATERNO NOMBRE): ";
	cin.ignore();
	getline(cin, alumno);
	cout << "Ingrese Nota (0 a 20): ";
	cin >> Nota;
	istringstream iss(alumno);
 	string s, part[4];
 	int i=0;
  	while ( getline( iss, s, ' ' ) ) {
  		part[i] = s.c_str();
  		i++;
  	}
  	Paterno = part[0];
  	Materno = part[1];
  	Nombre = part[2];
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
	string Paterno, Materno, Nombre, alumno;
	int Nota;
	cout << "Ingrese nombre completo (PATERNO MATERNO NOMBRE): ";
	cin.ignore();
	getline(cin, alumno);
	cout << "Ingrese Nota (0 a 20): ";
	cin >> Nota;
	istringstream iss(alumno);
 	string s, part[4];
 	int i=0;
  	while ( getline( iss, s, ' ' ) ) {
  		part[i] = s.c_str();
  		i++;
  	}
  	Paterno = part[0];
  	Materno = part[1];
  	Nombre = part[2];
	int pos = getAlumno(Paterno, Materno, Nombre, Nota);
	for(int i=pos; i<numAlumnos; i++){
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