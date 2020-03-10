#include <bits/stdc++.h>
using namespace std;
vector<int> v, tmp;
bool check[14];
int t;

void dfs(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < tmp.size(); i++) {
			cout << tmp[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		tmp.push_back(v[i]);
		dfs(i, cnt + 1);
		tmp.pop_back();
		check[i] = false;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (1) {
		cin >> t;
		if (t == 0) break;
		for (int i = 0; i < t; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		dfs(0, 0);

		v.clear();
		tmp.clear();
		memset(check, false, sizeof(check));
		cout << '\n';
	}
	return 0;
}