#include <iostream>
#include <vector>
#define MAX 7

using namespace std;

int arr[MAX];
vector<int> vec;
int n, m;

void Print() {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << '\n';

	return;
}

void DFS(int cnt) {
	if (cnt == m) {
		Print();
		return;
	}

	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
		DFS(cnt + 1);
		vec.pop_back();
	}
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		arr[i] = i + 1;
	
	DFS(0);
}