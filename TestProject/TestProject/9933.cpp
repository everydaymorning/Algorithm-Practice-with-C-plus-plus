#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	char res = 0;
	int res_len = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			string tmp = v[j];
			reverse(tmp.begin(), tmp.end());
			if (v[i] == tmp) {
				int s = v[i].size();
				res_len = s;
				res = v[i][s / 2];
			}
		}
	}
	cout << res_len << " " << res;
	return 0;
}