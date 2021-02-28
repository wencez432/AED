#include <iostream>

using namespace std;

void swap(int &x, int &y){
	int t = x;
	x = y;
	y = t;
}

void PrintArr(int arr[], int n){
	for(int i=0; i<n; i++)	cout << arr[i] << " ";
	cout << "\n";
}

void Print(int arr[], int s, int f){
	for(int i = s; i<=f; i++)	cout << arr[i] << " ";
	cout << "\n";
}

void MergeList(int arr[], int n, int s, int c, int f, int p){
	int temp[n];
	int i, j, k;
	i = k = s;
	j = c + 1;
	while(i<=c && j<=f){
		if(arr[i] <= arr[j]){
			temp[k] = arr[i];
			i++;	k++;
		}else{
			temp[k] = arr[j];
			j++;	k++;
		}
	}
	while(i<=c){
		temp[k++] = arr[i++];
	}
	while(j<=f){
		temp[k++] = arr[j++];
	}
	for(k=s; k<=f; k++)
		arr[k] = temp[k];
	cout << "MergeList " << p << ": ";	Print(arr, s, f);
}

void MergeSort(int arr[], int n, int s, int f, int p){
	int c;
	p += 1;
	if(s<f){
		c = (s+f)/2;
		cout << "MergeSort " << p << " (Izquierda): ";	Print(arr, s, c);
		MergeSort(arr, n, s, c, p);
		cout << "MergeSort " << p << " (Derecha): ";	Print(arr, c+1, f);
		MergeSort(arr, n, c+1, f, p);
		MergeList(arr, n, s, c, f, p);
	}
}

void HeapSort(int arr[], int n){
	bool flag;
	int i, hi, hd;
	while(n>1){
		flag = true;
		i = (n-1)/2;
		while(flag){
			if(i<0){
				flag = false;
				swap(arr[0], arr[n-1]);
			}
			else{
				hi = 2*i+1;
				hd = 2*i+2;
				if(hi<n){
					if(hd<n){
						if(arr[hd]>arr[i] && arr[hd]>=arr[hi])
							swap(arr[i], arr[hd]);
						else if(arr[hi]>arr[i] && arr[hi]>=arr[hd])
							swap(arr[i], arr[hi]);
					}
					else{
						if(arr[hi]>arr[i])
							swap(arr[i], arr[hi]);
					}
				}
			}
			i--;
		}
		n--;
	}
}

int getMax(int arr[], int n){ 
    int max = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
}

void countSort(int arr[], int n, int exp){ 
    int temp[n];
    int i, count[10] = { 0 };
    for(i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for(i = 1; i < 10; i++)
        count[i] += count[i - 1]; 
    for(i = n - 1; i >= 0; i--){
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = temp[i];
}

void RadixSort(int arr[], int n){
    int m = getMax(arr, n); 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp);
}

int main(int argc, char const *argv[]){
	int arr[] = {9,1,3,5,10,4,6};
	int n=7;
	int p = 0;
	cout << "Inicial: ";	PrintArr(arr, n);
	MergeSort(arr, n, 0, n-1, p);
	cout << "Final: ";	PrintArr(arr, n);
	//HeapSort(arr, n);
	//RadixSort(arr, n);
	//PrintArr(arr, n);
	return 0;
}