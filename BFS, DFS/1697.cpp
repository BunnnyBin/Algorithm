#include <iostream>
#include <queue>

using namespace std;

queue <int> q;
bool v[100001];  //들른 곳 표시
int result_time, cnt, seg;  // 총 걸리는 시간, 다음 섹션 카운트, 한 섹션

void hide_and_seek(int n, int k) {
	result_time = 0;
	seg = 1;

	v[n] = 1;
	q.push(n);

	while (!q.empty()) {
		cnt = 0;
		for (int i = 0;i < seg;i++) {
			int now = q.front();
			if (now == k)
				return;
			q.pop();

			int next;
			next = now - 1;
			if (next >= 0 && v[next] == 0) {
				q.push(next);
				v[next] = 1;
				cnt++;
			}
			next = now + 1;
			if (next <= 100000 && v[next] == 0) {
				q.push(next);
				v[next] = 1;
				cnt++;
			}
			next = now * 2;
			if (next <= 100000 && v[next] == 0) {
				q.push(next);
				v[next] = 1;
				cnt++;
			}
		}
		seg = cnt;
		if (cnt != 0) // cnt == 0이면 q.empty()를 의미한다.
			result_time++;
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= 100000; i++)
		v[i] = 0;

	hide_and_seek(n, k);
	cout << result_time << '\n';
}