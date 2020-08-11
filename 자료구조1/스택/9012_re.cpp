#include <iostream>
#include <stack>
#include <string>

using namespace std;

void bracket_check(string c) {
	stack<char> stk;

	for (int i = 0; i < c.length(); i++) {
		if (c[i] == '(')
			stk.push(c[i]);
		else {
			if (stk.empty()) {
				cout << "NO" << '\n';
				return;
			}
			stk.pop();
		}
	}
	if (!stk.empty()) {
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
}

int main(void) {
	int t;
	cin >> t;
	cin.ignore();

	while (t--) {
		string c; //string 안 쓰고 배열로 해도 됨
		getline(cin, c);

		bracket_check(c);
	}
}