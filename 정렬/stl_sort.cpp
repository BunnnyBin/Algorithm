#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���ÿ��� ������������ �ش����� ���� ������(���� �׻� Q(N*logN))
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	bool operator <(Student& student) { //�ٸ��л��� ���� ��
		return this->score < student.score;
	}
};
/*
bool compare(int a, int b) {
	return a < b; //��������(����Ʈ)
}
*/
bool compare(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b) {
	if (a.second.first == b.second.first)
		return a.second.second > b.second.second;
	else
		return a.second.first > b.second.first;
}

int main(void) {
	//1. ���� �⺻
	int a[10] = { 9,3,4,5,1,10,8,6,7,2 };
	sort(a, a + 10, compare);
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << '\n';


	//2. �ǹ�
	Student students[] = {
		Student("������", 90),
		Student("��Ұ�", 98),
		Student("�̼���", 72),
		Student("�þ���", 93),
	};
	sort(students, students + 4); //�˾Ƽ� ������ <�� ���
	for (int i = 0; i < 4; i++)
		cout << students[i].name << ' ';
	cout << '\n';


	//3. ��������
	vector<pair<int, string> > v; //first�� �������� sort
	v.push_back(pair<int, string>(90, "������"));
	v.push_back(pair<int, string>(100, "���ѿ�"));
	v.push_back(pair<int, string>(43, "�̼���"));
	v.push_back(pair<int, string>(97, "���ο�"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].second << ' ';
	cout << '\n';
}