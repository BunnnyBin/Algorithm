#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int n;

void quicksort(int start, int end) {
	if (start >= end)
		return;

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && vec[i] <= vec[key])
			i++;
		while (j > start && vec[j] >= vec[key])
			j--;

		if (i > j) {
			temp = vec[j];
			vec[j] = vec[key];
			vec[key] = temp;
		}
		else {
			temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	quicksort(start, j - 1);
	quicksort(j + 1, end);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	quicksort(0, n - 1);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << '\n';
}