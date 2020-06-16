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

//�������� - ���� ���� ���ڸ� ����
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

//�������� - ���� ���� �ִ� ���ڿ� ���ؼ� ��ȯ(���� ū ���ڰ� �� ������ ���� ����)
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

//�������� - ó���� ���ĵ� ����(���ĵ� ������ ����)
void Insertion_Sort() {
	int i, j, insert;

	for (i = 1; i < 10; i++) {
		insert = arr[i];
		for (j = i-1; j >=0; j--) { //���ĵ� ����(ū ������!!!)
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