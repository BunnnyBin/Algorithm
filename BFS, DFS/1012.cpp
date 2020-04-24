#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue <pair<int, int> > q;
int farm[50][50];
int direct[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int breadth_first_search(int width, int height, int number) {
	for (int i = 0; i < number; i++) {
		int x, y;
		cin >> x >> y;
		farm[y][x] = 1;
	}

	int bug_count = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (farm[y][x] == 1) {
				q.push(make_pair(x, y));
				farm[y][x] = 0; //µé¸¥ °÷
				bug_count++;

				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						pair<int, int> next = make_pair(now.first + direct[i][0], now.second + direct[i][1]);
						if (next.first >= 0 && next.first < width && next.second >= 0 && next.second < height && farm[next.second][next.first] == 1) {
							farm[next.second][next.first] = 0;
							q.push(next);
						}
					}
				}
			}
		}
	}
	return bug_count;
}

int main(void) {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int m, n, k;
		cin >> m >> n >> k;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				farm[y][x] = 0;

		cout << breadth_first_search(m, n, k) << '\n';
	}
}