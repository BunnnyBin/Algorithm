#include <iostream>

using namespace std;

//���� ���� �˰���, Q(N * logN)
//������ó�� ����ǰ� ���ҵ� ���ɼ��� ����
//�ֳ��ϸ� �ϴ� ������ ������ ������ ��ġ�� ������ �����Ѵ�!!!!
int number = 8;
int sorted[8];

//<�պ�>
void merge(int a[], int m, int middle, int n) { //������, �߰���, ����
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	//���� ������ ����
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	//���ĵ� �迭�� ���� -> sorted �迭�� a �迭�� �ű��
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}
//<����> - ����Լ�!!
void mergesort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergesort(a, m, middle);
		mergesort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	int a[8] = { 5, 1, 3, 4, 2, 8, 7, 6 };
	mergesort(a, 0, number - 1);

	for (int i = 0; i < number; i++)
		cout<< a[i] << '\n';
}