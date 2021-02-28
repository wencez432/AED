#include<iostream>
using namespace std;

void intercambiar(int &x, int &y){
	int t = x;
	x = y;
	y = t;
}

void printArray(int A[], int n){
	for (int i = 0; i < n; i++)
 		cout << A[i] << " ";
 	cout << "\n";
}

void sortIntercambio(int A[], int n){
	for (int i = 0; i < n-1; i++)
		for (int j = 1+i; j < n; j++)
			if (A[i] > A[j])	intercambiar(A[i], A[j]);
}

void sortSeleccion(int A[], int n){
 	int indMenor;
 	for (int i = 0; i < n-1; i++){
 		indMenor = i;
 		for (int j = i+1; j < n ; j++)
 			if (A[j]<A[indMenor])	indMenor = j;
 		if (indMenor != i)	intercambiar(A[i], A[indMenor]);
 	}
}

void sortInsercion(int A[], int n){
 	int t, j;
 	for (int i = 1; i < n; i++){
 		t = A[i];
 		for (j = i-1; j >= 0; j--){
 			if (A[j] > t)	A[j+1] = A[j];
 			else	break;
 		}
 		A[j+1] = t;
 	}
}

void sortBurbuja(int A[], int n){
	bool flag = true;
	for (int i = 0; i < n-1 && flag; i++){
		flag = false;
		for (int j = 0; j < n-i-1; j++)
			if (A[j] > A[j+1]){
				flag = true;
				intercambiar(A[i], A[i+1]);
			}
	}
}

void sortBurbujaBidireccional(int A[], int n){
	int izq = 0, der = n-1;
	bool flag = true;
	while(flag){
		flag = false;
		for (int i = izq; i < der; i++){
			if (A[i+1] < A[i]){
				flag = true;
				intercambiar(A[i], A[i+1]);
			}
		}
		der--;
		printArray(A, n);
		for (int i = der; i > izq; i--){
			if (A[i-1] > A[i]){
				flag = true;
				intercambiar(A[i], A[i-1]);
			}
		}
		izq++;
		printArray(A, n);
	}
}


int main(int argc, char const *argv[]){
	int A[20] = {20,19,18,17,16,15,14,13,12,11,1,2,3,4,5,6,7,8,9,10};
	int n = 20;
	cout << "Inicial: ";
	printArray(A, n);
	cout << "\n";
	sortBurbujaBidireccional(A, n);
	cout << "\n";
	cout << "Final: ";
 	printArray(A, n);
 	return 0;
}