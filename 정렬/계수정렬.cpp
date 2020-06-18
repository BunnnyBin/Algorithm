#include <iostream>

using namespace std;

//범위 조건인 한해서 빠른 알고리즘(Q(N))
//크기를 기준으로 샌다

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