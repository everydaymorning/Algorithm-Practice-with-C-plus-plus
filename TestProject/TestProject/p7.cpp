#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string begin1;
string target;
bool check[51];
int res = 55;
void dfs(string next, int cnt) {
	if (next == target) {
		res = min(res, cnt);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		int tmp = 0;
		for (int j = 0; j < next.size(); j++) {
			if (next[j] != v[i][j]) tmp++;
		}
		if (tmp == 1) {
			dfs(v[i], cnt + 1);
		}
		check[i] = false;
	}
}
int main() {
	cin >> begin1 >> target;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	dfs(begin1, 0);
	if (res == 55) cout << "0";
	else cout << res;
	return 0;
}