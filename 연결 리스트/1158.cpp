#include <iostream>
#include <list>
using namespace std;

int main() {
	int n, k;
	list<int>::iterator itr;

	cin >> n >> k;
	
	list<int> lst;

	//1~n������ ���ڳֱ�
	for (int i = 1; i <= n;i++) {
		lst.push_back(i);
	}

	//k��° ��� ����ϰ� �����ϱ�
	cout << "<";
	itr = lst.begin();
	while (lst.size() != 1) {
		for (int i = 0; i < k - 1; i++) {
			itr++;
			if (itr == lst.end())   //�̹� �ѹ����� ���Ҵٸ�
				itr = lst.begin();
		}
		cout << *itr << ", ";
		itr = lst.erase(itr); //erase �Լ��� ��ȯ���� ���� ���� ������ �ִ� ������ �ݺ���
		if (itr == lst.end())
			itr = lst.begin();
	}
	cout << *itr << ">";
}