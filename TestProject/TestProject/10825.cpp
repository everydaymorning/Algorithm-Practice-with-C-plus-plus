#include <bits/stdc++.h>
using namespace std;

class Student 
{
public:
	string name;
	int ko;
	int eng;
	int math;

};
bool cmp(Student const &s1, Student const &s2) {
	if (s1.ko != s2.ko) return s1.ko > s2.ko;
	if (s1.eng != s2.eng) return s1.eng < s2.eng;
	if (s1.math != s2.math) return s1.math > s2.math;
	return s1.name < s2.name;
}
Student s[100001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].ko >> s[i].eng >> s[i].math;
	}

	sort(s, s + n , cmp);

	for (int i = 0; i < n; i++) {
		cout << s[i].name << '\n';
	}
	return 0;
}