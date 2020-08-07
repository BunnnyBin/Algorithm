#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string str) {
	stack <char> s;
	int len = str.length();  //string.length() �Լ�

	for (int i = 0; i < len; i++) {
		if (str[i] == '(')  //string�ڷ����� �迭ó�� ��ȸ����!
			s.push(str[i]);
		else {
			if (!s.empty())
				s.pop();
			else 
				return 0;  //')'�� �� ���� ���
		}
	}
	if (!s.empty())
		return 0;  //'('�� �� ���� ���
	else 
		return 1;
}

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		string vps;
		cin >> vps;
		
		if (check(vps))
			cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}