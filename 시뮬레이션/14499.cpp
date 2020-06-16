#include <iostream>
#define MAX 20

using namespace std;

int dice[6];
int temp_dice[6];
int map[MAX][MAX];
int direct[1000];
int n, m, x, y, k;

void Dice(int dice_x, int dice_y) {
	for (int i = 0; i < k; i++) {
		int d0, d1, d2, d3, d4, d5;
		d0 = dice[0], d1 = dice[1], d2 = dice[2];
		d3 = dice[3], d4 = dice[4], d5 = dice[5];
		if (direct[i] == 1) { //동
			if (dice_x + 1 < m) {
				dice[0] = d1;
				dice[1] = d5;
				dice[3] = d0;
				dice[5] = d3;

				dice_x += 1;
			}
			else continue;
		}
		else if (direct[i] == 2) { //서
			if (dice_x - 1 >= 0) {
				dice[0] = d3;
				dice[1] = d0;
				dice[3] = d5;
				dice[5] = d1;

				dice_x -= 1;
			}
			else continue;
		}
		else if (direct[i] == 3) { //북
			if (dice_y - 1 >= 0) {
				dice[0] = d4;
				dice[2] = d0;
				dice[4] = d5;
				dice[5] = d2;

				dice_y -= 1;
			}
			else continue;
		}
		else if (direct[i] == 4) { //남
			if (dice_y + 1 < n) {
				dice[0] = d2;
				dice[2] = d5;
				dice[4] = d0;
				dice[5] = d4;

				dice_y += 1;
			}
			else continue;
		}
		//주사위가 이동했다면
		if (map[dice_y][dice_x] == 0) {
			map[dice_y][dice_x] = dice[5];
		}
		else {
			dice[5] = map[dice_y][dice_x];
			map[dice_y][dice_x] = 0;
		}

		cout << dice[0] << '\n';
	}
}

int main(void) {
	cin >> n >> m >> y >> x >> k;

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}

	for (int i = 0; i < k; i++)
		cin >> direct[i];

	Dice(x, y);
}