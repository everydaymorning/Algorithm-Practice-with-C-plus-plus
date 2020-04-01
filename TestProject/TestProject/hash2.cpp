#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<string, int> um;
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); i++) {
		um.insert({ v[i],1 });
	}
	bool flag = true;
	for (int i = 0; i < v.size(); i++) {
		string s;
		for (int j = 0; j < v[i].size(); j++) {
			s += v[i][j];
			if (um[s] && s != v[i]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	if (flag) {
		cout << "true";
	}
	else cout << "false";
	return 0;
}