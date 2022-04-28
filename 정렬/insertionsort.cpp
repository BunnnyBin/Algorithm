#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void InsertionSort(int arr[], int n) {
	int i, j, next;
	for (i = 1; i < n; i++) {
		next = arr[i]; //no sort section
		for (j = i - 1; j >= 0 && next < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = next;
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
	InsertionSort(arr, size);
	endTime = clock();

	printf("<<		After Sorting		>>\n");
	PrintArray(arr, size);

	timeDiff = (double)(endTime - startTime);
	cout << "Execution time = " << timeDiff << "ms" << endl;
}