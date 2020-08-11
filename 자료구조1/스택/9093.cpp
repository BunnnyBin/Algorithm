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
	cin.ignore(); //���� ����

	while (t--) {
		string word;
		
		getline(cin, word); //���� ���ö� ���� ���ڿ� �Է�
		
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
		//word += '\n', if(word[i] == ' ' || word[i] == '\n')���� Ǯ�� �Ʒ��� �ʿ�x 
		while (!stk.empty()) {
			cout << stk.top();
			stk.pop();
		}
		cout << '\n';
	}
}
