#include <iostream>
#include <string>

using namespace std;

struct Queue {
	int queue[10001];
	int begin;
	int end;

	Queue() {
		begin = 0;
		end = 0;
	}

	bool empty() {
		if (begin == end) return 1;
		else return 0;
	}
	void push(int x) {
		queue[end++] = x;
		return;
	}
	int pop() {
		if (empty()) return -1;
		return queue[begin++];
	}
	int size() {
		return end - begin;
	}
	int front() {
		if (empty()) return -1;
		return queue[begin];
	}
	int back() {
		if (empty()) return -1;
		return queue[end - 1];
	}
};

int main(void) {
	Queue q;
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	while (n--) {
		string cmd;

		cin >> cmd;

		if (!cmd.compare("push")) {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (!cmd.compare("pop")) {
			cout << q.pop() << '\n';
		}
		else if (!cmd.compare("size")) {
			cout << q.size() << '\n';
		}
		else if (!cmd.compare("empty")) {
			cout << q.empty() << '\n';
		}
		else if (!cmd.compare("front")) {
			cout << q.front() << '\n';
		}
		else if (!cmd.compare("back")) {
			cout << q.back() << '\n';
		}
	}
}