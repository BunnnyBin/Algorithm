#include <iostream>
#include <cstring>

using namespace std;

int stk[10001];
int stk_size; //!top대신에 size로 구현해보기!

//Stack 클래스를 생성해서 메소드를 넣는 방법도 있다.
bool empty() {
	if (stk_size == 0)
		return 1;
	else
		return 0;
}

void push(int num) {
	stk[stk_size] = num;
	stk_size++;
	return;
}

int pop() {
	if (empty())
		return -1;
	stk_size--;
	return stk[stk_size];
}

int size() {
	return stk_size;
}

int top() {
	if (empty())
		return -1;
	return stk[stk_size - 1];
}

int main(void) {
	int n;//명령어의 개수

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		char cmd[50];
		int num;

		cin >> cmd;
		
		if (!strcmp(cmd, "push")) {
			cin >> num;
			push(num);
		}
		else if (!strcmp(cmd, "pop")) {
			cout << pop() << '\n';
		}
		else if (!strcmp(cmd, "size")) {
			cout << size() << '\n';
		}
		else if (!strcmp(cmd, "empty")) {
			cout << empty() << '\n';
		}
		else if (!strcmp(cmd, "top")) {
			cout << top() << '\n';
		}
	}
}