#include <iostream>
#include <queue>
//굳이 큐로 풀 필요없는 문제 
using namespace std;

queue <int> q;

int main(void) {
	int n, k;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ',' << ' ';
	}
	cout << '>';
}
