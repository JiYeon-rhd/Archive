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

void quick_sort(int l, int R)
{
	int i, j;
	int temp, t;

	if (R > l) {
		temp = L[l];
		i = l;
		j = R + 1;
		do {
			do { i = i + 1; } while (L[i] < temp);
			do { j = j - 1; } while (L[j] > temp);
			if (i < j) {
				t = L[i];
				L[i] = L[j];
				L[j] = t;
			}

		} while (j > i);
		t = L[j];
		L[j]=L[l];
		L[l] = t;
		quick_sort(l, j - 1);
		quick_sort(j + 1, R);
	}	
}


void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	quick_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}