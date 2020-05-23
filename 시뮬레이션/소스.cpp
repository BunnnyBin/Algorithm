#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	//array
	int a[4] = { 1,2,3,4 };
	do {
		for (int i = 0; i < 4; i++)
			cout << a[i] << ' ';
		cout << '\n';
	} while (next_permutation(a, a + 4));

	//vector
	vector<int> b = { 1,2,3,4 };
	do {
		for (int i = 0; i < 4; i++)
			cout << b[i] << ' ';
		cout << '\n';
	} while (next_permutation(b.begin(), b.end()));
}