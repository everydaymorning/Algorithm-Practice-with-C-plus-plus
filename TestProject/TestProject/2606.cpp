#include <bits/stdc++.h>
using namespace std;
vector<int> v[101];
bool check[101];
queue<int> q;
int cnt;
void dfs(int s) {
	check[s] = true;
	cnt++;
	for (int i = 0; i < v[s].size(); i++) {
		int next = v[s].at(i);
		if (check[next]) continue;
		dfs(next);
	}

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int c, n;
	cin >> c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << cnt - 1;
	return 0;
}