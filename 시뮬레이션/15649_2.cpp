/*그러나 오름차순으로 출력이 되지 않는 문제가 있다
  따라서 next_permutation으로 해당 문제를 풀기에는 한계가 있다
  https://redcoder.tistory.com/7
  select = {0,0,1,2}처럼 순서를 할 수 밖에 없는 이유는 next_permutation의 내부적 구조때문이다. 위의 사이트 참고 바람*/
#include <iostream>
#include <algorithm>
#define MAX 8

using namespace std;

int n, m;
int arr[MAX]; //수열 숫자
int select[MAX]; //핵심

void func() {
	do {
		int seq[MAX] = {}; //수열
		for (int i = 0; i < n; i++) {
			if (select[i]) {
				seq[select[i] - 1] = arr[i];
			}
		}
		
		for (int i = 0; i < m; i++)
			cout << seq[i] << ' ';
		cout << '\n';
	} while (next_permutation(select, select + n));
}

int main(void) {
	cin >> n >> m;

	select[m] = 1;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
		if (i > m)
			select[i] = select[i - 1] + 1 ;  // select = {0,0,1,2}
	}
	
	func();
}