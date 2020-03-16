#include <bits/stdc++.h>
using namespace std;
bool check[101];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string pattern;
	cin >> pattern;
	int p_size = pattern.length();
	bool flag = false;
	string start, end;

	for (int i = 0; i < p_size; i++) {
		if (pattern[i] == '*') {
			flag = true;
			continue;
		}

		if (!flag) start += pattern[i];
		else end += pattern[i];

	}
	int s_size = start.size();
	int e_size = end.size();
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int str_size = str.size();
		string tmp1, tmp2;
		bool flag1 = false;
		for (int j = 0; j < s_size; j++) {
			if (start[j] != str[j]) {
				flag1 = true;
				break;
			}
			check[j] = true;
		}
		if (flag1) {
			cout << "NE" << '\n';
			continue;
		}
		int idx = str_size - 1;
		for (int j = e_size - 1; j >= 0; j--) {
			if (check[idx] || end[j] != str[idx]) {
				flag1 = true;
				break;
			}
			idx--;
		}
		if (flag1) cout << "NE" << '\n';
		else cout << "DA" << '\n';
		memset(check, false, sizeof(check));
	}
	return 0;
}