#include <iostream>

using namespace std;

//여태까지 버블,선택,삽입 정렬은 Q(N * N)
//분할 정복 알고리즘(배열을 반으로 나눈다)
//Q(N * logN) -> logN은 굉장히 작은 숫자로 상수로 봐도 무난할 정도
int number = 10;

void Quick_Sort(int *data, int start, int end) {
	if (start >= end) //피벗구간이 원소1개인 경우
		return;

	int key = start; //피벗
	int i = start + 1; //왼쪽 시작점
	int j = end; //오른쪽 시작점
	int temp;

	while (i <= j) { //엇갈릴 때까지 반복
		while (data[i] <= data[key] && i <=end ) //피벗보다 큰값 만날때까지 이동
			i++;
		while (data[j] >= data[key] && j > start) //피벗보다 작은 값 만날때까지 이동
			j--;

		if (i > j) { //엇갈린 상태이면
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}

	Quick_Sort(data, start, j - 1);
	Quick_Sort(data, j+1, end);
}

void Quick_Sort_desc(int* data, int start, int end) {
	if (start >= end)
		return;

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (data[i] >= data[key] && i <= end)
			i++;
		while (data[j] <= data[key] && j > start)
			j--;

		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	Quick_Sort_desc(data, start, j - 1);
	Quick_Sort_desc(data, j + 1, end);
}

int main(void) {
	int data[] = { 1,10,5,8,7,6,4,3,2,9 };

	//Quick_Sort(data, 0, number - 1);
	Quick_Sort_desc(data, 0, number - 1);
	for (int i = 0; i < number; i++)
		cout << data[i] << ' ';
	cout << '\n';
	return 0;
}