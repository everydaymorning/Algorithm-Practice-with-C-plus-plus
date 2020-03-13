#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
	string tmp1, tmp2;
	for (int i = 0; i < a.size(); i++) {
		tmp1 += tolower(a[i]);
	}

	for (int i = 0; i < b.size(); i++) {
		tmp2 += tolower(b[i]);
	}
	return tmp1 < tmp2;
}
int main() {
	while (1) {
		int a;
		cin >> a;
		if (a == 0) break;
		vector<string> v;
		for (int i = 0; i < a; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		sort(v.begin(), v.end(), cmp);
		cout << v[0] << '\n';
	}
	return 0;
}