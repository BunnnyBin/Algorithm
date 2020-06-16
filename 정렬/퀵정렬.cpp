#include <iostream>

using namespace std;

//���±��� ����,����,���� ������ Q(N * N)
//���� ���� �˰���(�迭�� ������ ������)
//Q(N * logN) -> logN�� ������ ���� ���ڷ� ����� ���� ������ ����
int number = 10;

void Quick_Sort(int *data, int start, int end) {
	if (start >= end) //�ǹ������� ����1���� ���
		return;

	int key = start; //�ǹ�
	int i = start + 1; //���� ������
	int j = end; //������ ������
	int temp;

	while (i <= j) { //������ ������ �ݺ�
		while (data[i] <= data[key] && i <=end ) //�ǹ����� ū�� ���������� �̵�
			i++;
		while (data[j] >= data[key] && j > start) //�ǹ����� ���� �� ���������� �̵�
			j--;

		if (i > j) { //������ �����̸�
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