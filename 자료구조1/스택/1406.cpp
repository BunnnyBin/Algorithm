#include <iostream>
#include <string>
#include <stack>

using namespace std;

//stk1 -> stk2로 보내고 그때그때 다시 stk2 -> stk1으로 할 필요가 없다 - 시간초과
stack<char> stk1; //left stack(커서의 왼쪽)
stack<char> stk2; //right stack(커서의 오른쪽)

void P(char c) {
	stk1.push(c);
	return;
}

void B() {
	if (!stk1.empty()) {
		stk1.pop();
	}
	return;
}

void L() {
	if (!stk1.empty()) {
		stk2.push(stk1.top());
		stk1.pop();
	}
	return;
}

void D() {
	if (!stk2.empty()) {
		stk1.push(stk2.top());
		stk2.pop();
	}
	return;
}

int main(void) {
	string str;
	int m;

	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
		stk1.push(str[i]);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m;

	while (m--) {
		char cmd;
		cin >> cmd;

		if (cmd == 'P') {
			char ch;
			cin >> ch;
			P(ch);
		}
		else if (cmd == 'L') {
			L();
		}
		else if (cmd == 'D') {
			D();
		}
		else if (cmd == 'B') {
			B();
		}
	}
	
	while (!stk1.empty()) {
		stk2.push(stk1.top());
		stk1.pop();
	}
	while (!stk2.empty()) {
		cout << stk2.top();
		stk2.pop();
	}
	cout << '\n';
}