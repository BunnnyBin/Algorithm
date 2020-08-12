#define M 10001
#include <iostream>
#include <string>

using namespace std;

struct Deque {
	int head, tail;
	int deque[M * 2 + 1];

	Deque() {
		head = tail = M;
	}

	void push_front(int x) {
		deque[--head] = x;
		return;
	}
	void push_back(int x) {
		deque[tail++] = x;
		return;
	}
	bool empty() {
		if (head == tail) return 1;
		else return 0;
	}
	int pop_front() {
		if (empty()) return -1;
		return deque[head++];
	}
	int pop_back() {
		if (empty()) return -1;
		return deque[--tail];
	}
	int size() {
		return tail - head;
	}
	int front() {
		if (empty()) return -1;
		return deque[head];
	}
	int back() {
		if (empty()) return -1;
		return deque[tail - 1];
	}
};

int main(void) {
	Deque deq;
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;

		if (!cmd.compare("push_front")) {
			int x;
			cin >> x;
			deq.push_front(x);
		}
		else if (!cmd.compare("push_back")) {
			int x;
			cin >> x;
			deq.push_back(x);
		}
		else if (!cmd.compare("pop_front")) {
			cout << deq.pop_front() << '\n';
		}
		else if (!cmd.compare("pop_back")) {
			cout << deq.pop_back() << '\n';
		}
		else if (!cmd.compare("size")) {
			cout << deq.size() << '\n';
		}
		else if (!cmd.compare("empty")) {
			cout << deq.empty() << '\n';
		}
		else if (!cmd.compare("front")) {
			cout << deq.front() << '\n';
		}
		else if (!cmd.compare("back")) {
			cout << deq.back() << '\n';
		}
	}
}