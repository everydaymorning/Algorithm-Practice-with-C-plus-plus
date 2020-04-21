#include <bits/stdc++.h>
using namespace std;

int main() {
	int size = 1000;
	string s = "abcabcdede";
	string ans;
	string tmp;
	string tmp2;
	int s_size = s.size();
	bool con = false;
	for (int i = 1; i <= s_size / 2; i++) {
		tmp = s.substr(0, i);
		ans += tmp;
		int cnt = 1;
		int idx = 0;
		for (int j = i; j < s.size(); j++) {
			tmp2 = s.substr(j, i);
			j += (i - 1);
			cout << "tmp: " << tmp << "  tmp2: " << tmp2 << '\n';

			if (tmp == tmp2) {
				cnt++;
			}
			else {
				if (cnt > 1) {
					string num = to_string(cnt);
					ans = num + ans;
					ans += tmp2;
					cnt = 1;
					con = true;
				}
				else {
					idx = j;
					break;
				}
			}
			tmp2 = "";

		}
		if (!con) {
			ans = s;
		}
		else {
			cout << "idx: " << idx << '\n';
			for (int j = idx; j < s.size(); j++) {
				ans += s[j];
			}
		}
		cout << "ans: " << ans << '\n';

		int ans_size = ans.size();
		size = min(size, ans_size);
		cout << "size: " << size << '\n';
		tmp = "";
		ans = "";

	}
	return 0;
}