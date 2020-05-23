/*�׷��� ������������ ����� ���� �ʴ� ������ �ִ�
  ���� next_permutation���� �ش� ������ Ǯ�⿡�� �Ѱ谡 �ִ�
  https://redcoder.tistory.com/7
  select = {0,0,1,2}ó�� ������ �� �� �ۿ� ���� ������ next_permutation�� ������ ���������̴�. ���� ����Ʈ ���� �ٶ�*/
#include <iostream>
#include <algorithm>
#define MAX 8

using namespace std;

int n, m;
int arr[MAX]; //���� ����
int select[MAX]; //�ٽ�

void func() {
	do {
		int seq[MAX] = {}; //����
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