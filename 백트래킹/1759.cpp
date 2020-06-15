#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 16

using namespace std;

vector<char> vec;
char arr[MAX]; //문자열이므로 한칸 공백 필요
int C, L;

void Print() {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i];
	cout << '\n';
	return;
}

void DFS(int cnt, int launch, int mo, int ja) {
	if (cnt == L) {
		if(mo >= 1 && ja >= 2)
			Print();
		return;
	}

	for (int i = launch; i < C; i++) {
		vec.push_back(arr[i]);
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			DFS(cnt + 1, i + 1, mo + 1, ja);
		else DFS(cnt + 1, i + 1, mo, ja + 1);
		
		vec.pop_back();
	}
}

int main(void) {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + C);
	DFS(0, 0, 0, 0);
}
