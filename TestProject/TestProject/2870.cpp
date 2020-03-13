#include <bits/stdc++.h>
using namespace std;
vector<string> v;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) continue;
			else {
				return a[i] < b[i];
			}
		}
	}
	return a.size() < b.size();
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str, tmp;
		cin >> str;
		bool flag = false;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] >= '0' && str[j] <= '9') {
				tmp += str[j];
				flag = true;
			}
			else {
				if (flag) {
					while (1) {
						if (tmp.size() > 1 && tmp[0] == '0') {
							tmp = tmp.substr(1, tmp.size() - 1);
						}
						else {
							break;
						}
					}
					v.push_back(tmp);
				}
				flag = false;
				tmp = "";
			}
		}
		if (flag) {
			while (1) {
				if (tmp.size() > 1 && tmp[0] == '0') {
					tmp = tmp.substr(1, tmp.size() - 1);
				}
				else {
					break;
				}
			}
			v.push_back(tmp);
		}
		flag = false;
		tmp = "";
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}