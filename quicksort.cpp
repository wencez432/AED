#include<iostream>

using namespace std;

void swap(int &x, int &y){
	int t = x;
	x = y;
	y = t;
}

void printArray(int A[], int s, int f){
	for (int i = s; i <= f; i++)
 		cout << A[i] << " ";
 	cout << "\n";
}

void QuickSort(int A[], int l, int h){
	int pivpos = (l+h)/2, i = l, j = h;
	int piv = A[pivpos];
	while(i<=j){
		while(A[i] < piv)	i++;
		while(A[j] > piv)	j--;
		if(i<=j){
			swap(A[i],A[j]);
			i++;
			j--;
		}
	}
	if(l < j){
		printArray(A,l,j);
		QuickSort(A,l,j);
	}
	if(i < h){
		printArray(A,i,h);
		QuickSort(A,i,h);
	}
}

int main(int argc, char const *argv[]){
	int A[] = {79,21,15,99,88,65,75,85,76,46,84,24};
	int n = 12;
	cout << "Inicial: ";
	printArray(A,0,n-1);
	QuickSort(A,0,n-1);
	cout << "Final: ";
 	printArray(A,0,n-1);
	return 0;
}