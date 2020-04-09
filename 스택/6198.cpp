#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	
	stack<int> s;
	vector<int> vec(80000);
	int num, input, total, count;
	
	cin >> num;

	total = 0;
	for (int i = 0; i < num; i++) {
		cin >> vec[i];
	}
	
	for (int i = 0; i < num - 1; i++) {
		s.push(vec[i]);
		count = 0;

		for (int j = i + 1; j < num; j++) {
			if (s.top() > vec[j]) {
				count++;
			}
			else
				break;
		}
		total += count;
		s.pop();
	}
	cout << total;
}