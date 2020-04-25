#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

queue <pair<int, int> > q;  // 누적 시간, 현재 위치
bool v[100001];  //들른 곳 표시
int result_time, n, k;

void hide_and_seek() {
	v[n] = 1;
	q.push(make_pair(0, n));
	result_time = INT_MAX;

	while (!q.empty()) {
		int pos = q.front().second;
		int time = q.front().first;

		if (pos == k) {
			result_time = min(result_time, time);
		}
		q.pop();
		
		if (pos * 2 <= 100000 && v[pos * 2] == 0) {
			q.push(make_pair(time, pos * 2));
			v[pos * 2] = 1;
		}
		if (pos - 1 >= 0 && v[pos - 1] == 0) {
			q.push(make_pair(time + 1, pos - 1));
			v[pos - 1] = 1;
		}
		if (pos + 1 <= 100000 && v[pos + 1] == 0) {
			q.push(make_pair(time + 1, pos + 1));
			v[pos + 1] = 1;
		}
	}
	return;
}

int main(void) {
	cin >> n >> k;

	for (int i = 0; i <= 100000; i++)
		v[i] = 0;

	hide_and_seek();
	cout << result_time << '\n';
}