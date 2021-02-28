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

void shell(int A[], int n){
	bool flag = true;
	int s = n/2, r=1, c;
	cout << "Recorrido\tSalto\tIntercambios\t\t\tLista\n";
	while(s > 0){
		while(flag){
			cout << r << "\t\t" << s << "\t";
			flag = false;
			c = 0;
			for(int i = s; i < n; i++){
				if(A[i-s] > A[i]){
					cout << "(" << A[i-s] << "," << A[i] << ") ";
					intercambiar(A[i-s],A[i]);
					c++;
					flag = true;
				}
			}
			if(!flag) cout << "ninguno";
			if(c<2)	cout << "\t\t";
			cout << "\t\t";
			printArray(A, n);
			r++;
		}
		if(s/2 > 0)	cout << "salto " << s << "/2 = " << s/2 << "\n";
		s = s/2;
		flag = true;
	}
}

void printArray2(int A[], int inicio, int fin){
	for (int i = inicio; i < fin; i++)
 		cout << A[i] << " ";
 	cout << "\n";
}

void QuickSort(int A[], int primero, int ultimo){
	int i,j,central;
	int pivote;
	central = (primero + ultimo)/2;
	pivote = A[central];
	i=primero;
	j=ultimo;
	do{
		while(A[i]<pivote) i++;
		while(A[j]>pivote) j--;
		if(i<=j){
			intercambiar(A[i],A[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(primero<j){
		QuickSort(A, primero, j);
	}
	if(i<ultimo){
		QuickSort(A, i, ultimo);
	}
}

int main(int argc, char const *argv[]){
	int A[] = {79,21,15,99,88,65,75,85,76,46,84,24};
	int n = 12;
	cout << "Inicial: ";
	printArray(A, n);
	cout << "\n";
	QuickSort(A, 0, n-1);
	cout << "\n";
	cout << "Final: ";
 	printArray(A, n);
	return 0;
}