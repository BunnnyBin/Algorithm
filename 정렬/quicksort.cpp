#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void QuickSort(int arr[], int left, int right) {
	int pivot, i, j;
	int temp;

	if (left < right) {
		i = left;
		j = right + 1;
		pivot = arr[left];
		do {
			do i++; while (arr[i] < pivot);
			do j--; while (arr[j] > pivot);
			if (i < j) { //swap
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		} while (i < j);
		//swap
		temp = arr[left]; //pivot
		arr[left] = arr[j];
		arr[j] = temp;

		QuickSort(arr, left, j - 1);
		QuickSort(arr, j + 1, right);
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
	QuickSort(arr, 0, size - 1);
	endTime = clock();

	printf("<<		After Sorting		>>\n");
	PrintArray(arr, size);

	timeDiff = (double)(endTime - startTime);
	cout << "Execution time = " << timeDiff << "ms" << endl;
}