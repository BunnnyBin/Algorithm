/*탐색:dfs(백트래킹), 바이러스 감염경로:bfs*/
#include <iostream>
#include <queue>
#include <vector>
#define MAX 8

using namespace std;

int map[MAX][MAX];
queue<pair<int, int>> q;
vector<pair<int, int> > virus;
int direct[4][2] = { {0,1}, {0,-1},{1,0},{-1,0} };
int safe_area, bfs_area, max_area;
int n, m;

//바이러스의 위치(x1, y1)
void BFS(int x1, int y1, bool visited[][MAX]) {
	bfs_area = 0;

	visited[y1][x1] = true;
	q.push(make_pair(x1, y1));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(now.first + direct[i][0], now.second + direct[i][1]);
			if (next.first < m && next.first >= 0 && next.second < n && next.second >= 0 && !visited[next.second][next.first] && map[next.second][next.first] == 0) {
				q.push(next);
				visited[next.second][next.first] = true;
				bfs_area++;
			}
		}
	}
}

void DFS(int cnt, int x, int y) {
	if (cnt == 3) {
		int area = safe_area - 3;
		bool visited[MAX][MAX] = { 0, };
		for (int i = 0;i < virus.size(); i++) {
			BFS(virus[i].first, virus[i].second, visited);
			area -= bfs_area;
		}
		if (max_area < area)
			max_area = area;
		
		return;
	}

	if (x >= m) {
		x = 0;
		y++;
	}
	if (y >= n)
		return;

	if (map[y][x] == 0) {
		map[y][x] = 1;
		DFS(cnt + 1, x + 1, y);
		map[y][x] = 0;
	}
	DFS(cnt, x + 1, y);
}

int main(void) {
	cin >> n >> m;

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				safe_area++;
			if (map[i][j] == 2)
				virus.push_back(make_pair(j, i));
		}

	DFS(0, 0, 0);
	cout << max_area << '\n';
}