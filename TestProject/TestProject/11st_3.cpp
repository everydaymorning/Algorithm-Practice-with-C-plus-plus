#include <bits/stdc++.h>
using namespace std;
bool check[9];
bool visit[1001];
string str;
string pattern;
vector<char> v;
vector<string> res;
int cnt;
void dfs(int cnt) {
	if (cnt == pattern.size()) {
		string s;
		for (int i = 0; i < v.size(); i++) {
			s += v[i];
		}
		res.push_back(s);
	}

	for (int i = 0; i < pattern.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		v.push_back(pattern[i]);
		dfs(cnt + 1);
		v.pop_back();
		check[i] = false;
	}
}
int main() {
	
	cin >> str;
	cin >> pattern;


	dfs(0);
	
	for (int i = 0; i < str.size() - pattern.size() + 1; i++) {
		bool flag = false;
		for (int j = 0; j < pattern.size(); j++) {
			if (str[i] == pattern[j]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			string s = str.substr(i, pattern.size());
			for (int j = 0; j < res.size(); j++) {
				if (res[j] == s) {
					cnt++;
					break;
				}
			}
		}
	}

	cout << cnt;


	return 0;
}