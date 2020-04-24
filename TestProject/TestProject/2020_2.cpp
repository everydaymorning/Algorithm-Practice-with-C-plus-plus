#include <bits/stdc++.h>
using namespace std;
string u, v;
bool check_right(string str) {
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (s.empty()) {
			s.push(str[i]);
		}
		else {
			if (str[i] == ')') {
				if (s.top() == '(') {
					s.pop();
				}
				else {
					s.push(str[i]);
				}
			}
			else if (str[i] == '(') {
				s.push(str[i]);
			}
		}
	}
	if (s.empty()) {
		return true;
	}
	else return false;
}

string convert(string str) {
	if (str.empty()) {
		return "";
	}
	int cnt1 = 0;
	int cnt2 = 0;
	int idx = 0;
	string u1 = "";
	string v1 = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			cnt1++;
			u1 += str[i];
		}
		else if (str[i] == ')') {
			cnt2++;
			u1 += str[i];
		}
		if (cnt1 == cnt2) {
			idx = i + 1;
			break;
		}
	}

	for (int i = idx; i < str.size(); i++) {
		v1 += str[i];
	}
	cout << "u1: " << u1 << "  v1: " << v1 << '\n';
	if (check_right(u1)) {
		return u1 + convert(v1);
	}
	else {
		string tmp1 = convert(v1);
		cout << "tmp1: " << tmp1 << '\n';
		string tmp2 = "";
		for (int i = 1; i < u1.size() - 1; i++) {
			if (u1[i] == '(') {
				tmp2 += ')';
			}
			else if (u1[i] == ')') {
				tmp2 += '(';
			}
		}
		cout << "tmp2: " << tmp2 << '\n';

		string tmp3 = "(" + tmp1 + ")" + tmp2;
		return tmp3;
	}
}
string solution(string p) {
	if (check_right(p)) {
		return p;
	}
	string a = convert(p);

	return a;
}

int main() {
	string p = ")()(";
	string ans = solution(p);
	cout << ans;
	return 0;
}