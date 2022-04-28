#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void InsertionSort(int arr[], int n) {
	int i, j, next;
	for (i = 1; i < n; i++) {
		next = arr[i];
		for (j = i - 1; j >= 0 && next < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = next;
	}
}

void BucketSort(int arr[], int n) {
	int bucket = 0;
	int i,j,k;
	if (n == 1000)
		bucket = 50;
	else if (n == 5000)
		bucket = 250;
	else if (n == 10000)
		bucket = 500;
	else
		bucket = n / 20;

	int ** bucket_arr = new int* [bucket];
	for (i = 0; i < bucket; i++)
		bucket_arr[i] = new int[n];
	int count[500] = {0,}; //bucket_arr's bucket count

	//Scatter
	int val_bucket = 0;
	for (k = 0; k < n; k++) {
		val_bucket = arr[k] / 20; //0 ~ (bucket-1)
		if (val_bucket == bucket) //last number -> (bucket - 1)
			val_bucket--;
		bucket_arr[val_bucket][count[val_bucket]] = arr[k];
		count[val_bucket] += 1;
	}
	//Sort
	for (i = 0; i < bucket; i++) {
		if (count[i] != 0)
			InsertionSort(bucket_arr[i], count[i]);
	}
	//Gather
	int idx = 0;
	for (i = 0; i < bucket && idx < n; i++) {
		for (j = 0; j < count[i]; j++) {
			arr[idx] = bucket_arr[i][j];
			idx++;
		}
	}
	//delete
	for (i = 0; i < bucket; i++)
		delete [] bucket_arr[i];
	delete [] bucket_arr;
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
	BucketSort(arr, size);
	endTime = clock();

	printf("<<		After Sorting		>>\n");
	PrintArray(arr, size);

	timeDiff = (double)(endTime - startTime);
	cout << "Execution time = " << timeDiff << "ms" << endl;
}