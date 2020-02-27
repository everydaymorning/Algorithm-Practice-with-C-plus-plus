#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str, tmp;
	getline(cin, str);
	getline(cin, tmp);

	if (tmp.size() > str.size()) {
		cout << "0";
	}
	else {
		int cnt = 0;

		for (int i = 0; i < str.size() - tmp.size() + 1; i++) {
			bool flag = false;

			for (int j = 0; j < tmp.size(); j++) {
				if (str[i + j] != tmp[j]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cnt++;
				i += tmp.size() - 1;
			}
		}
		cout << cnt;

	}
	return 0;
}