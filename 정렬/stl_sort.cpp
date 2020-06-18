#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//평상시에는 퀵정렬이지만 극단적인 경우는 힙정렬(따라서 항상 Q(N*logN))
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	bool operator <(Student& student) { //다른학생과 비교할 때
		return this->score < student.score;
	}
};
/*
bool compare(int a, int b) {
	return a < b; //오름차순(디폴트)
}
*/
bool compare(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b) {
	if (a.second.first == b.second.first)
		return a.second.second > b.second.second;
	else
		return a.second.first > b.second.first;
}

int main(void) {
	//1. 제일 기본
	int a[10] = { 9,3,4,5,1,10,8,6,7,2 };
	sort(a, a + 10, compare);
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << '\n';


	//2. 실무
	Student students[] = {
		Student("김유빈", 90),
		Student("김소고", 98),
		Student("이순자", 72),
		Student("시언지", 93),
	};
	sort(students, students + 4); //알아서 연산자 <를 사용
	for (int i = 0; i < 4; i++)
		cout << students[i].name << ' ';
	cout << '\n';


	//3. 코테위주
	vector<pair<int, string> > v; //first를 기준으로 sort
	v.push_back(pair<int, string>(90, "김유빈"));
	v.push_back(pair<int, string>(100, "김한울"));
	v.push_back(pair<int, string>(43, "이소희"));
	v.push_back(pair<int, string>(97, "강민우"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].second << ' ';
	cout << '\n';
}