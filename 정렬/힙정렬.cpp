#include <iostream>
#include <vector>

using namespace std;

//힙 트리 구조를 이용 - 힙(완전 이진 트리를 이용하여 최대값,최솟값)
//즉,힙 생성 알고리즘(Heapify Algorithm)를 통해 깨진 힙구조를 힙으로 유지 - Q(logN)
//퀵 정렬, 합병 정렬처럼 Q(N * logN)
int heap[100000] = { -1, };
int number;

//힙 생성 알고리즘 - Q(logN)
void heapify(int i) {
	//왼쪽 자식 노드와 오른쪽 자식 노드 비교
	int c = 2 * i;
	if (c < number && heap[c] < heap[c + 1]) {
		c++;
	}
	//부모랑 자식을 비교
	if (heap[i] < heap[c]) {
		int temp = heap[i];
		heap[i] = heap[c];
		heap[c] = temp;
	}

	if (c <= number / 2) heapify(c); //Q(1/2logN)
}

//모든 정점에 대해서 힙 생성 알고리즘 적용 - Q(N)
//최상위 노드를 최하위 노드와 바꾼다(정렬)
int main(void) {
	cin >> number;
	for (int i = 1; i <= number; i++) {
		cin >> heap[i];
	}
	//밑에서부터 힙 생성
	for (int i = number / 2; i >= 1; i--) {
		heapify(i);
	}
	
	//정렬 수행(i : 최하위 자식)
	for (int i = number; i >= 1; i--) {
		for (int j = 1; j <= number; j++) {
			cout << heap[j] << ' ';
		}
		cout << '\n';

		int temp = heap[1];
		heap[1] = heap[i];
		heap[i] = temp;
		//위에서부터 heapify
		int root = 1;
		int c;
		do {
			c = 2 * root;
			if (c < i - 1 && heap[c] < heap[c + 1]) c++;
			if (c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
}