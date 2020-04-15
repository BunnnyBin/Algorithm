#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, int> > q;
vector<int> draw[500];
int direct[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;
int number = 0;

//최대 넓이 반환
int breadth_first_search() {
	int max_area = 0;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if (draw[y][x] == 1) {
				number++;
				int area = 1;
				q.push(make_pair(x, y));
				draw[y][x] = -1; //들른 곳
				
				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						pair<int, int> next = make_pair(now.first + direct[i][0], now.second + direct[i][1]);
						if (next.first >= 0 && next.first <= m - 1 && next.second >= 0 && next.second <= n - 1 && draw[next.second][next.first] == 1) {
							draw[next.second][next.first] = -1;
							q.push(next);
							area++;
						}
					}
				}
				if (max_area < area)
					max_area = area;
			}
		}
	return max_area;
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			draw[i].push_back(num);
		}

	int max_area = breadth_first_search();
	cout << number << '\n';
	cout << max_area;
	return 0;
}