#include <iostream>
#include <list>
using namespace std;

int main() {
	list<char> str;
	list<char>::iterator cursor;
	string init;
	char com, add;
	int m;

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> init;

	for (int i = 0; i < init.size(); i++)
		str.push_back(init[i]);

	cin >> m;
	cursor = str.end();
	for (int i = 0; i < m; i++) {
		cin >> com;

		if (com == 'L') {
			if (cursor != str.begin())
				cursor--;
		}
		else if (com == 'D') {
			if (cursor != str.end())
				cursor++;
		}
		else if (com == 'B') {
			if (cursor != str.begin()) 
				cursor = str.erase(--cursor);
		}
		else if (com == 'P') {
			cin >> add;
			str.insert(cursor, add); //insert : ¿ŞÂÊ¿¡ ¿ä¼Ò »ğÀÔ
		}
	}
	for (list<char>::iterator itr = str.begin(); itr != str.end(); ++itr)
		cout << *itr;
}