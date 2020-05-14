#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
stack <pair<int, int> > stk;  //x, y
int domain[100][100] = { 0 }; // 0:»öÄ¥x, 1: »öÄ¥o
int visited[100][100] = { 0 }; //0:¹æ¹®x, 1: ¹æ¹®o
vector<int> area_array;  //³ĞÀÌ ÀúÀå
int direct[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void dfs() {
	for(int y = 0;y< m;y++){
		for (int x = 0; x < n; x++) {
			if (domain[y][x] == 0 && visited[y][x] == 0) {
				int domain_area = 0;  //¿µ¿ª ³ĞÀÌ

				stk.push(make_pair(x, y));
				visited[y][x] = 1;

				//dfs
				while (!stk.empty()) {
					pair<int, int> now = stk.top();
					stk.pop();
					domain_area++;

					for (int i = 0; i < 4; i++) {
						pair<int, int> next = make_pair(now.first + direct[i][0], now.second + direct[i][1]);
						if (next.first >= 0 && next.first <= n - 1 && next.second >= 0 && next.second <= m - 1 && domain[next.second][next.first] == 0 && visited[next.second][next.first] == 0) {
							stk.push(next);
							visited[next.second][next.first] = 1;
						}
					}
				}
				area_array.push_back(domain_area);
			}
		}
	}
}

int main(void) {
	cin >> m >> n >> k;
	
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		x2--;
		y2--;

		for (int i = y1; i <= y2; i++) {
			for (int j = x1; j <= x2; j++) {
				domain[i][j] = 1;
			}
		}
	}

	dfs();
	cout << area_array.size() << '\n';
	sort(area_array.begin(), area_array.end());
	for (int i = 0; i < area_array.size(); i++)
		cout << area_array[i] << ' ';
}