#include <bits/stdc++.h>
using namespace std;
struct stu {
	int a;
	int b;
	int c;
};
vector<stu> v;

bool cmp(stu a, stu b) {
	return a.c > b.c;
}
int check[101];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		stu tmp;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		check[v[i].a]++;
		cnt++;
		if (check[v[i].a] > 2) continue;
		cout << v[i].a << " " << v[i].b << '\n';
		if (cnt >= 3) break;
	}
	return 0;
}