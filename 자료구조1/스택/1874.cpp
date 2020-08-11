#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int arr[100001];
vector <char> vec;
stack<int> stk;

int main(void) {
	int n;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		arr[i] = num;
	}

	int i = 0;
	for (int x = 1; x <= n; x++) {
		stk.push(x);
		vec.push_back('+');

		while (!stk.empty()) {
			if (stk.top() == arr[i]) {
				vec.push_back('-');
				stk.pop();
				i++;
			}
			else break;
		}
	}

	if (!stk.empty()) {
		cout << "NO" << '\n';
		return 0;
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
}