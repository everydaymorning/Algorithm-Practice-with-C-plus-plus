#include <bits/stdc++.h>
using namespace std;
struct girlGroup{
	string group;
	set<string> s;
};
int main() {
	int n, m;
	cin >> n >> m;
	vector<girlGroup> v(n);
	for (int i = 0; i < n; i++) {
		string groups;
		cin >> groups;
		v[i].group = groups;
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			string s;
			cin >> s;
			v[i].s.insert(s);
		}
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int tmp;
		cin >> tmp;
		
		if (tmp == 0) {
			for (int j = 0; j < n; j++) {
				if (v[j].group == s) {
					set<string>::iterator it;
					for (it = v[j].s.begin(); it != v[j].s.end(); it++) {
						cout << *it << '\n';
					}
				}
			}
		}
		else if (tmp == 1) {
			for (int j = 0; j < n; j++) {
				set<string>::iterator it;
				for (it = v[j].s.begin(); it != v[j].s.end(); it++) {
					if (*it == s) {
						cout << v[j].group << '\n';
					}
				}
			}
		}
	}
	return 0;
}