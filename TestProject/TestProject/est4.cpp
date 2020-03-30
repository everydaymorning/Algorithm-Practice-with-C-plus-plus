#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	string email = "Example";
	string S = "John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jan Doe; Peter Brian Parker";
	vector<string> v;
	string tmp;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ';') {
			v.push_back(tmp);
			tmp.clear();
			continue;
		}
		else if (S[i] == ' ') {
			if (tmp.empty()) {
				continue;
			}
		}
		tmp += S[i];
	}
	v.push_back(tmp);
	for (int i = 0; i < email.size(); i++) {
		email[i] = tolower(email[i]);
	}
	vector<string> v1;

	for (int i = 0; i < v.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == ' ') cnt++;
		}
		if (cnt == 1) {
			string s;
			for (int j = v[i].size() - 1; j >= 0; j--) {
				if (v[i][j] == ' ') {
					for (int k = 0; k < s.size(); k++) {
						s[k] = tolower(s[k]);
					}
					reverse(s.begin(), s.end());
					v1.push_back(s);
					s.clear();
					continue;
				}
				s += v[i][j];
			}
			for (int k = 0; k < s.size(); k++) {
				s[k] = tolower(s[k]);
			}
			reverse(s.begin(), s.end());
			v1.push_back(s);
			s.clear();
		}
		
		else if (cnt == 2) {
			string s;
			bool flag = false;
			for (int j = v[i].size() - 1; j >= 0; j--) {
				if (v[i][j] == ' ') {
					if (flag) {
						s.clear();
						continue;
					}
					for (int k = 0; k < s.size(); k++) {
						s[k] = tolower(s[k]);
					}
					reverse(s.begin(), s.end());
					v1.push_back(s);
					s.clear();
					flag = true;
					continue;
				}
				if (v[i][j] == '-') continue;
				s += v[i][j];
			}
			for (int k = 0; k < s.size(); k++) {
				s[k] = tolower(s[k]);
			}
			reverse(s.begin(), s.end());
			v1.push_back(s);
			s.clear();
		}

	}


	for (int i = 0; i < v1.size() - 1; i++) {
		string t = v1[i] + v1[i + 1];
		int num = 2;
		for (int j = i + 2; j < v1.size() - 1; j+=2) {
			string tt = v1[j] + v1[j + 1];
			if (t == tt) {
				string str_num = to_string(num);
				v1[j + 1] += str_num;
				num++;
			}
		}
	}

	vector<string> v2;
	for (int i = 0; i < v1.size() - 1; i++) {
		string s;
		s += ('<' + v1[i] + '_' + v1[i + 1] + '@' + email + ".com" + '>');
		v2.push_back(s);
		i++;
	}
	string res;
	for (int i = 0; i < v2.size(); i++) {
		if (i == v2.size() - 1) res += (v[i] + " " + v2[i]);
		else res += (v[i] + " " + v2[i] + "; ");
	}

	cout << res;
	return 0;
}