#include <iostream>
#include <vector>

using namespace std;

//�� Ʈ�� ������ �̿� - ��(���� ���� Ʈ���� �̿��Ͽ� �ִ밪,�ּڰ�)
//��,�� ���� �˰���(Heapify Algorithm)�� ���� ���� �������� ������ ���� - Q(logN)
//�� ����, �պ� ����ó�� Q(N * logN)
int heap[100000] = { -1, };
int number;

//�� ���� �˰��� - Q(logN)
void heapify(int i) {
	//���� �ڽ� ���� ������ �ڽ� ��� ��
	int c = 2 * i;
	if (c < number && heap[c] < heap[c + 1]) {
		c++;
	}
	//�θ�� �ڽ��� ��
	if (heap[i] < heap[c]) {
		int temp = heap[i];
		heap[i] = heap[c];
		heap[c] = temp;
	}

	if (c <= number / 2) heapify(c); //Q(1/2logN)
}

//��� ������ ���ؼ� �� ���� �˰��� ���� - Q(N)
//�ֻ��� ��带 ������ ���� �ٲ۴�(����)
int main(void) {
	cin >> number;
	for (int i = 1; i <= number; i++) {
		cin >> heap[i];
	}
	//�ؿ������� �� ����
	for (int i = number / 2; i >= 1; i--) {
		heapify(i);
	}
	
	//���� ����(i : ������ �ڽ�)
	for (int i = number; i >= 1; i--) {
		for (int j = 1; j <= number; j++) {
			cout << heap[j] << ' ';
		}
		cout << '\n';

		int temp = heap[1];
		heap[1] = heap[i];
		heap[i] = temp;
		//���������� heapify
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