#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<int> s;
	int num;

	cin >> num;
	for (int i = 0; i < num; i++) {
		string com;
		cin >> com;
		if (!com.compare("push")) { //str.compare() - c에서의 strcmp()
			int com_end;
			cin >> com_end;         //또는 if(com == "push") 
			s.push(com_end);
		}
		else if (!com.compare("pop")) {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (!com.compare("size")) {
			cout << s.size() << '\n';
		}
		else if (!com.compare("empty")) {
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (!com.compare("top")) {
			if (s.empty())
				cout << -1 << '\n';
			else 
				cout << s.top() << '\n';
		}
	}
}