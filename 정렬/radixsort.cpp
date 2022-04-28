#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>

using namespace std;

queue<int> Q[10]; //1~9

void RadixSort(int arr[], int size) {
	int MaxRadix;
	int i, j, index, div;
	//compute max radix
	for (MaxRadix = 1; MaxRadix <= size; MaxRadix *= 10) {} // size can be max number

	for (i = 1; i < MaxRadix; i *= 10) {
		for (j = 0; j < size; j++) {
			if (arr[j] < i) index = 0;
			else {
				div = arr[j] / i;
				index = div % 10;
			}
			Q[index].push(arr[j]);
		}
		//pop process
		int n = 0;
		for (j = 0; j < 10; j++) {
			while (Q[j].empty() == 0) {
				arr[n] = Q[j].front();
				Q[j].pop();
				n++;
			}
		}
	}
}

int* InputArray(int size) {
	int* arr;

	arr = (int*)malloc(sizeof(int) * size);

	srand((unsigned int)time(NULL)); //random number
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size + 1;
	}
	return arr;
}

void PrintArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

int main(void) {
	clock_t startTime, endTime;
	double timeDiff;
	int* arr;
	int size;

	printf("input size: ");
	scanf("%d", &size);

	arr = InputArray(size);
	printf("<<		Before Sorting		>>\n");
	PrintArray(arr, size);

	startTime = clock();
	RadixSort(arr, size);
	endTime = clock();

	printf("<<		After Sorting		>>\n");
	PrintArray(arr, size);

	timeDiff = (double)(endTime - startTime);
	cout << "Execution time = " << timeDiff << "ms" << endl;
}