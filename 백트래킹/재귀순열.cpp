#include <iostream>
#include<vector>
#define MAX 5
using namespace std;

int arr[MAX];
bool visited[MAX];
vector<int> vec;

void print() {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << '\n';
}

void dfs(int cnt) {  //cnt == count¾àÀÚ
	if (cnt == 3) {
		print();
		return;
	}

	for (int i = 0; i < MAX; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		vec.push_back(arr[i]);
		dfs(cnt + 1);
		vec.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	dfs(0);
}