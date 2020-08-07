#include <iostream>
#include <string>

using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

int empty(int dat[]) {
	if (head == tail)
		return 1;
	else return 0;
}

void push_front(int dat[], int data) {
	dat[--head] = data;
}

void push_back(int dat[], int data) {
	dat[tail++] = data;
}

int pop_front(int dat[]) {
	if (empty(dat))
		return -1;
	return dat[head++];
}

int pop_back(int dat[]) {
	if (empty(dat))
		return -1;
	return dat[--tail];
}

int size(int dat[]) {
	return tail - head;
}

int front(int dat[]) {
	if (empty(dat))
		return - 1;
	return dat[head];
}

int back(int dat[]) {
	if (empty(dat))
		return -1;
	return dat[tail - 1];
}

int main() {
	int num;

	cin >> num;

	for (int i = 0; i < num; i++) {
		string com;
		cin >> com;

		if (com == "push_front") {
			int com_end;
			cin >> com_end;

			push_front(dat, com_end);
		}
		else if (com == "push_back") {
			int com_end;
			cin >> com_end;

			push_back(dat, com_end);
		}
		else if (com == "pop_front") {
			cout << pop_front(dat) << '\n';
		}
		else if (com == "pop_back") {
			cout << pop_back(dat) << '\n';
		}
		else if (com == "size") {
			cout << size(dat) << '\n';
		}
		else if (com == "empty") {
			cout << empty(dat) << '\n';
		}
		else if (com == "front") {
			cout << front(dat) << '\n';
		}
		else if (com == "back") {
			cout << back(dat) << '\n';
		}
	}
}