#include<iostream>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

int N;

class Student {
public:
	string name;
	int kor;
	int eng;
	int math;
};
vector<Student> s;

void Print() {
	for (int i = 0; i < s.size(); i++) {
		cout << s[i].name << '\n';
	}
}

bool compare(Student a, Student b) {
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) {
		return a.name < b.name;
	}
	else if (a.kor == b.kor && a.eng == b.eng) {
		return a.math > b.math;
	}
	else if (a.kor == b.kor) {
		return a.eng < b.eng;
	}
	else
		return a.kor > b.kor;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	int kor, eng, math;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name >> kor >> eng >> math;
		Student tmp;
		tmp.name = name;
		tmp.kor = kor;
		tmp.eng = eng;
		tmp.math = math;
		s.push_back(tmp);
	}
	sort(s.begin(), s.end(), compare);
	Print();

	return 0;
}