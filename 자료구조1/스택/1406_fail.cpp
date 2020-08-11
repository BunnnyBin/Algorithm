#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> stk1;
stack<char> stk2;
int cursor;

void move_to_2() {
	while (cursor != stk1.size() - 1) { //커서가 스택 맨 위가 될때까지 옮긴다
		stk2.push(stk1.top());
		stk1.pop();
	}
	return;
}

void back_to_1() {
	while (!stk2.empty()) {
		stk1.push(stk2.top());
		stk2.pop();
	}
	return;
}

void P(char c) {
	move_to_2();
	stk1.push(c);
	cursor = stk1.size() - 1;
	back_to_1();
	return;
}

void B() {
	move_to_2();
	if (!stk1.empty()) {
		stk1.pop();
		cursor = stk1.size() - 1;
	}
	back_to_1();
	return;
}

void L() {
	if (cursor != -1)
		cursor--;
	return;
}

void D() {
	if (cursor != stk1.size() - 1)
		cursor++;
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
	
	cursor = stk1.size() - 1;

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
	
	cursor = -1;
	move_to_2();
	int len = stk2.size();
	for (int i = 0; i < len; i++) {
		cout << stk2.top();
		stk2.pop();
	}
	cout << '\n';
}