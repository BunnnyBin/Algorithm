#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

queue <pair<int, int> >	q;
char pill[101][101];
bool dist[101][101];
int direct[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
int n;

int not_redgreen() {
	int number = 0; //영역 개수

	for(int y = 1;y <= n;y++)
		for (int x = 1; x <= n; x++) {
			if (dist[y][x] != true) {
				char now_pill = pill[y][x];
				q.push(make_pair(x, y));
				dist[y][x] = true; //들른 곳
				number++; //영역 카운트

				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						pair<int, int> next = make_pair(now.first + direct[i][0], now.second + direct[i][1]);
						if (next.first >= 1 && next.first <= n && next.second >= 1 && next.second <= n && dist[next.second][next.first] != true && now_pill == pill[next.second][next.first]) {
							q.push(next);
							dist[next.second][next.first] = true;
						}
					}
				}
			}
		}
	return number;
}

int redgreen() {
	int number = 0; //영역 개수

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			if (dist[y][x] != true) {
				if (pill[y][x] == 'G')
					pill[y][x] = 'R';
				char now_pill = pill[y][x];
				q.push(make_pair(x, y));
				dist[y][x] = true; //들른 곳
				number++; //영역 카운트

				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						pair<int, int> next = make_pair(now.first + direct[i][0], now.second + direct[i][1]);
						if (pill[next.second][next.first] == 'G')
							pill[next.second][next.first] = 'R';

						if (next.first >= 1 && next.first <= n && next.second >= 1 && next.second <= n && dist[next.second][next.first] != true && now_pill == pill[next.second][next.first]) {
							q.push(next);
							dist[next.second][next.first] = true;
						}
					}
				}
			}
		}
	return number;
}

int main(void) {
	cin >> n;
	cin.ignore(); //엔터키 무시

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = false;
			scanf("%1c", &pill[i][j]);
		}
		cin.ignore(); //엔터키 무시
	}

	cout << not_redgreen() << ' '; 
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			dist[i][j] = false;
	cout << redgreen() << '\n';
}