#include <iostream>

using namespace std;

//���� ������ ���ؼ� ���� �˰���(Q(N))
//ũ�⸦ �������� ����

int temp;
int counting[6];
int arr[20] = { 1,3,2,4,3,2,4,2,5,2,
				1,3,4,4,5,1,2,3,4,1 };

void counting_sort() {
	for (int i = 1; i <= 5; i++)
		counting[i] = 0;

	for (int i = 0; i < 20; i++)
		counting[arr[i]]++;

	for (int i = 1; i <= 5; i++) {
		if (counting[i] != 0) {
			for (int j = 0; j < counting[i]; j++)
				cout << i;
		}
	}
}

int main(void) {
	counting_sort();
}