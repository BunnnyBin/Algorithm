#include <iostream>
#define MAX 100000

using namespace std;

int arr[10];
int min, temp;

void Print() {
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << '\n';
}

//선택정렬 - 가장 작은 숫자를 선택
void Select_Sort() {
	for (int i = 0; i < 10; i++) {
		min = i;
		for (int j = i; j < 10; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

//버블정렬 - 당장 옆에 있는 숫자와 비교해서 교환(가장 큰 숫자가 맨 끝으로 가는 기적)
void Bubble_Sort() {
	for(int i=1;i<10;i++)
		for (int j = 0; j < 10 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
}

//삽입정렬 - 처음이 정렬된 구간(정렬된 구간에 삽입)
void Insertion_Sort() {
	int i, j, insert;

	for (i = 1; i < 10; i++) {
		insert = arr[i];
		for (j = i-1; j >=0; j--) { //정렬된 구간(큰 수부터!!!)
			if (arr[j] > insert) {
				arr[j + 1] = arr[j];
			}
			else break;
		}
		arr[j + 1] = temp;
	}
}

int main(void) {
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	//Select_Sort();
	Bubble_Sort();
	Print();
}