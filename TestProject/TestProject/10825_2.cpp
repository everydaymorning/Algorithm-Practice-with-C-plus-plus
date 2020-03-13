#include <bits/stdc++.h>
using namespace std;
struct stu {
	string name;
	int a;
	int b;
	int c;
};
vector<stu> v;

bool cmp(stu a, stu b) {
	if (a.a == b.a && a.b == b.b && a.c == b.c) {
		return a.name < b.name;
	}
	else if (a.a == b.a && a.b == b.b) {
		return a.c > b.c;
	}
	else if (a.a == b.a) {
		return a.b < b.b;
	}
	return a.a > b.a;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;
		stu tmp;
		tmp.name = name;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << v[i].name << '\n';
	}
	return 0;
}