#include <bits/stdc++.h>
using namespace std;
int s, e;
bool check[10001];
string bfs(int start) {

	queue<pair<int, string>> q;
	q.push(make_pair(start, ""));
	check[start] = true;

	while (!q.empty()) {
		auto cur = q.front();
		int cur_x = cur.first;
		string cur_y = cur.second;
		q.pop();

		if (cur_x == e) return cur_y;

		int nx = 2 * cur_x;
		if (nx > 9999) nx = nx % 10000;
		if (!check[nx]) {
			check[nx] = true;
			q.push(make_pair(nx, cur_y + "D"));
		}

		nx = cur_x - 1;
		if (nx < 0) nx = 9999;
		if (!check[nx]) {
			check[nx] = true;
			q.push(make_pair(nx, cur_y + "S"));
		}

		nx = (cur_x % 1000) * 10 + (cur_x / 1000);
		if (!check[nx]) {
			check[nx] = true;
			q.push(make_pair(nx, cur_y + "L"));
		}

		nx = (cur_x / 10) + ((cur_x % 10) * 1000);
		if (!check[nx]) {
			check[nx] = true;
			q.push(make_pair(nx, cur_y + "R"));
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> s >> e;
		string result = bfs(s);
		cout << result << '\n';
		memset(check, false, sizeof(check));
	}
	return 0;
}