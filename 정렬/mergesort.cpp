#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10000

using namespace std;

int mergedarr[MAX_SIZE];

// the sorted array arr[i:j] and arr[j+1:last] are merged into mergedarr[z:last]
void Merge(int arr[], int first, int mid, int last) {
	int i, j, z, t;
	i = first;
	j = mid + 1; //index for second merged array
	z = first; // index for mergearr[]

	while (i <= mid && j <= last) {
		if (arr[i] <= arr[j]) 
			mergedarr[z++] = arr[i++];
		else
			mergedarr[z++] = arr[j++];
	}
	//left value is all copyed
	if (i > mid) {
		for (t = j; t <= last; t++)
			mergedarr[z++] = arr[t];
	}
	else {
		for (t = i; t <= mid; t++)
			mergedarr[z++] = arr[t];
	}
	// merrgedarr's value is copyed to arr
	for (t = first; t <= last; t++)
		arr[t] = mergedarr[t];
}

void MergeSort(int arr[], int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		MergeSort(arr, first, mid);
		MergeSort(arr, mid + 1, last);
		Merge(arr, first, mid, last);
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
	MergeSort(arr, 0, size-1);
	endTime = clock();

	printf("<<		After Sorting		>>\n");
	PrintArray(arr, size);

	timeDiff = (double)(endTime - startTime);
	cout << "Execution time = " << timeDiff << "ms" << endl;
}