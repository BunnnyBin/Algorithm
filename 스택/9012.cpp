#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string str) {
	stack <char> s;
	int len = str.length();  //string.length() 함수

	for (int i = 0; i < len; i++) {
		if (str[i] == '(')  //string자료형은 배열처럼 조회가능!
			s.push(str[i]);
		else {
			if (!s.empty())
				s.pop();
			else 
				return 0;  //')'가 더 많은 경우
		}
	}
	if (!s.empty())
		return 0;  //'('가 더 많은 경우
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