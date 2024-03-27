#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void merge(int L[], int l, int r, int m) {
	int i, j, k;
	int R[SIZE];

	for (i = l; i <= m; i++)
		R[i] = L[i];
	for (j = m; j < r; j++)
		R[r + m - j] = L[j + 1];
	
	i = l;
	j = r;
	for (k = l; k <= r; k++)
		L[k] = (R[i] < R[j]) ? R[i++]:R[j--]; 

}

void merge_sort(int a[], int l, int r)
{
	int m;
	
	if (r > l) {
		m = (r + l) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, l, r, m);
	}
}




void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	merge_sort(L,0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}