#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int,int> > q;
vector<int> dist[100];  //출발점과의 거리(방문여부) : -1로 초기화
vector<int> mazz[100];
int direct[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
int n, m;

void breadth_first_search() {
	dist[0][0] = 1;
	q.push(make_pair(0, 0));  //pair.first : x축, pair.second : y축
							  //배열[y축][x축]
	while (!q.empty()) {
		pair<int,int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(now.first + direct[i][0], now.second + direct[i][1]);
			if (next.first >= 0 && next.first <= m - 1 && next.second >= 0 && next.second <= n - 1 && mazz[next.second][next.first] == 1 && dist[next.second][next.first] == -1) {
				q.push(next);
				dist[next.second][next.first] = dist[now.second][now.first] + 1;
			}
		}
	}
	return;
}

int main(void) {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int num;
			scanf("%1d", &num);
			mazz[i].push_back(num);
			dist[i].push_back(-1);
		}
	breadth_first_search();
	cout << dist[n - 1][m - 1];
	return 0;
}