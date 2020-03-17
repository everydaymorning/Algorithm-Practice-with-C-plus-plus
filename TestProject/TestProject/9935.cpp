#include <bits/stdc++.h>
using namespace std;
char res[1000001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str;
	cin >> str;
	string bomb;
	cin >> bomb;
	int b_size = (int)bomb.size();
	int idx = 0;
	for (int i = 0; i < str.size(); i++) {
		res[idx] = str[i];
		idx++;
		if (res[idx - 1] == bomb[b_size - 1]) {

			if (idx - b_size < 0) continue;
			bool flag = true;
			for (int j = 0; j < bomb.size(); j++) {
				if (res[idx - j - 1] != bomb[b_size - j - 1]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				idx -= b_size;
			}
		}
	}
	if (idx == 0) cout << "FRULA";
	else {
		for (int i = 0; i < idx; i++) {
			cout << res[i];
		}
	}
	return 0;
}