#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

vector<int> vec;
int sorted[MAX];
int n;

void merge(int m, int middle, int n) {
	if (m < n) {
		int i = m;
		int j = middle + 1;
		int k = m;

		while (i <= middle && j <= n) {
			if (vec[i] <= vec[j]) {
				sorted[k] = vec[i];
				i++;
			}
			else {
				sorted[k] = vec[j];
				j++;
			}
			k++;
		}
		//남은 것 처리
		if (i <= middle) {
			for (int t = i; t <= middle; t++) {
				sorted[k] = vec[t];
				k++;
			}
		}
		else{
			for (int t = j; t <= n; t++) {
				sorted[k] = vec[t];
				k++;
			}
		}
		//원래 배열로 삽입
		for (int t = m; t <= n; t++)
			vec[t] = sorted[t];
	}
}

void mergesort(int m, int n) {
	if (m < n) {
		int middle = (n + m) / 2;
		mergesort(m, middle);
		mergesort(middle + 1, n);
		merge(m, middle, n);
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	mergesort(0, n - 1);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << '\n';
}