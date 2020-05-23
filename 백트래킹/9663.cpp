#include <iostream>
#include <vector>
#define MAX 15

using namespace std;

vector<bool> visited1(MAX);
vector<bool> visited2(MAX + MAX);
vector<bool> visited3(MAX + MAX);
int result, n;

void Queen(int x) {
	if (x == n) {
		result++;
		return;
	}
	for (int y = 0; y < n; y++) {
		if (visited1[y] || visited2[x + y] || visited3[x - y + n - 1]) continue;
		visited1[y] = true;
		visited2[x + y] = true;
		visited3[x - y + n - 1] = true;

		Queen(x + 1);
		visited1[y] = false;
		visited2[x + y] = false;
		visited3[x - y + n - 1] = false;
	}
}

int main(void) {
	cin >> n;

	result = 0;

	Queen(0);

	cout << result << '\n';
}
