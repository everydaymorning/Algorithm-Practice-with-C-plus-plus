#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		cin >> n;
		deque<int> dq;

		string r;
		cin >> r;
		string tmp;
		tmp = "";
		for (int i = 0; i < r.length(); i++) {
			if (n == 0) break;
			if (r[i] != '[' && r[i] != ']' && r[i] != ',') {
				tmp += r[i];
			}
			else {
				if (r[i] == '[') continue;
				else {
					dq.push_back(atoi(tmp.c_str()));
					tmp = "";
				}
			}
		}
		bool dir = false;
		bool flag = true;
		int str_len = str.length();
		for (int i = 0; i < str_len; i++) {
			if (str[i] == 'R') {
				dir = !dir;
			}
			else {
				if (dq.size() == 0) {
					flag = !flag;
					cout << "error" << '\n';
					break;
				}
				
				if (dir == false) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		int dq_size = dq.size();
		if (flag) {
			if (dq_size == 0) {
				cout << "[]" << '\n';
			}
			else {
				cout << "[";
				if (dir == false) {
					for (int i = 0; i < dq_size; i++) {
						if (i == dq_size - 1) cout << dq.front() << "]";
						else cout << dq.front() << ",";
						dq.pop_front();
					}
				}
				else {
					for (int i = 0; i < dq_size; i++) {
						if (i == dq_size - 1) cout << dq.back() << "]";
						else cout << dq.back() << ",";
						dq.pop_back();
					}
				}
				cout << '\n';
			}
		}
	}
	return 0;
}