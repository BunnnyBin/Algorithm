#include <iostream>
#include <list>
using namespace std;

int main() {
	int n, k;
	list<int>::iterator itr;

	cin >> n >> k;
	
	list<int> lst;

	//1~n번까지 숫자넣기
	for (int i = 1; i <= n;i++) {
		lst.push_back(i);
	}

	//k번째 사람 출력하고 삭제하기
	cout << "<";
	itr = lst.begin();
	while (lst.size() != 1) {
		for (int i = 0; i < k - 1; i++) {
			itr++;
			if (itr == lst.end())   //이미 한반퀴를 돌았다면
				itr = lst.begin();
		}
		cout << *itr << ", ";
		itr = lst.erase(itr); //erase 함수의 반환값이 삭제 원소 다음에 있는 원소의 반복자
		if (itr == lst.end())
			itr = lst.begin();
	}
	cout << *itr << ">";
}