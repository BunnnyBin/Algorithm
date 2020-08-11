#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int arr[100001];
vector <char> vec;  //vector말고 string으로도 가능 
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
	
	//다른 방법 : arr[i] > x 인 경우(무조건 push)와 그 반대의 경우(무조건 pop)를 나누어 생각하기 
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
