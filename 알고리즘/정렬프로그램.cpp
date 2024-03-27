#include <iostream>
#define SWAP(x,y,temp) ((temp)=(x),(x)=(y),(y)=(temp))
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void sort()
{
	int least, temp; //least는 가장 작은값, temp 임시 변수

	for (int i = 0; i < SIZE - 1; i++) {
		least = i;

		//최솟값 찾기
		for (int j = i + 1; j < SIZE; j++) {
			if (L[j] < L[least])
				least = j;
		}

		if (i != least) {
			SWAP(L[i], L[least], temp);
		}
	}
}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	sort();

	cout << "\n\nSorted Data : ";
	print_data();

}
