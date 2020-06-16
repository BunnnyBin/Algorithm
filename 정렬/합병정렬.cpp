#include <iostream>

using namespace std;

//분할 정복 알고리즘, Q(N * logN)
//퀵정렬처럼 편향되게 분할될 가능성이 없다
//왜냐하면 일단 무조건 반으로 나누고 합치는 순간에 정렬한다!!!!
int number = 8;
int sorted[8];

//<합병>
void merge(int a[], int m, int middle, int n) { //시작점, 중간점, 끝점
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
	//남은 데이터 삽입
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
	//정렬된 배열을 삽입 -> sorted 배열을 a 배열에 옮기기
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}
//<분할> - 재귀함수!!
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