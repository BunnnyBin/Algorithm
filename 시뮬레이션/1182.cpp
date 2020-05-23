#include <iostream>
#include <algorithm>
#define MAX 20

using namespace std;

int arr[MAX];
bool selected[MAX];
int n, s, result;

void part_sequence(int cnt) {
	for (int i = 0; i < n; i++) {
		if (i >= n - cnt)
			selected[i] = true; // ex. cnt = 2 : select = {0,0,0,1,1}
	}

	do {
		int total = 0;
		for (int i = 0; i < n; i++) {
			if (selected[i])
				total += arr[i];
		}
		if (total == s)
			result++;
	} while (next_permutation(selected, selected + n));
}

int main(void) {
	result = 0;

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		part_sequence(i);
	}

	cout << result << '\n';
}