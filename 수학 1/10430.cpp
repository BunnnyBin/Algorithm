#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;

	cout << (a + b) % c << '\n';
	cout << ((a % c) + (b % c)) % c << '\n';
	cout << (a * b) % c << '\n';
	cout << ((a % c) * (b % c)) % c << '\n';
}