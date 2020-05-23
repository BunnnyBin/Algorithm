#include <iostream>
#include <vector>
#define MAX 8

using namespace std;

int arr[MAX];  //수열 숫자
vector<int> vec;  //수열
bool visited[MAX][MAX];  //각 cnt단계의 방문여부 - 0으로 초기화됨
int cnt, n, m;

void Print() {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ' ';
	}
	cout << '\n';
}

void DFS(int cnt, int s) {
	if (cnt == m) {
		Print();
		return;
	}

	for (int i = s; i < n; i++) {
		if (visited[cnt][i]) continue;
		visited[cnt][i] = true;
		vec.push_back(arr[i]);
		DFS(cnt + 1, arr[i] - 1);
		visited[cnt][i] = false;
		vec.pop_back();
	}
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	DFS(0, 0);
}