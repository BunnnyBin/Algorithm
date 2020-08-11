#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	int t;
	stack<char> stk;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	cin.ignore(); //엔터 무시

	while (t--) {
		string word;
		
		getline(cin, word); //엔터 나올때 까지 문자열 입력
		
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == ' ') {
				while (!stk.empty()) {
					cout << stk.top();
					stk.pop();
				}
				cout << " ";
			}
			else {
				stk.push(word[i]);
			}
		}
		while (!stk.empty()) {
			cout << stk.top();
			stk.pop();
		}
		cout << '\n';
	}
}