#include <bits/stdc++.h>
using namespace std;

int main() {
	int size = 1000;
	string s = "xababcdcdababcdcd";
	string tmp;
	string tmp2;
	vector<string> v;
	int s_size = s.size();
	for (int i = 1; i <= s_size / 2; i++) {
		tmp = s.substr(0, i);
		int cnt = 1;
		for (int j = i; j < s.size(); j++) {
			tmp2 = s.substr(j, i);
			j += (i - 1);

			if (tmp == tmp2) {
				cnt++;
			}
			else {
				if (cnt > 1) {
					string num = to_string(cnt);
					v.push_back(num + tmp);
				}
				else {
					v.push_back(tmp);
				}
				tmp = tmp2; // 기준 문자열 변경
				cnt = 1;
			}

		}
		if (cnt > 1) {
			string num = to_string(cnt);
			v.push_back(num + tmp);
		}
		else {
			v.push_back(tmp);
		}
		string str;
		for (int j = 0; j < v.size(); j++) {
			str += v[j];
		}

		int str_size = str.size();
		size = min(size, str_size);
		tmp = "";
		v.clear();
	}
	if (s_size == 1) cout << "1";
	else cout << size;
	return 0;
}