#include <bits/stdc++.h>
using namespace std;
bool check[10001];
int t;

void bfs(int a, int b) {
	queue<pair<int, string>> q;
	check[a] = true;
	q.push({ a,"" });

	while (!q.empty()) {
		int num = q.front().first;
		string res = q.front().second;
		q.pop();

		if (num == b) {
			cout << res << '\n';
			return;
		}

		int next = num * 2;
		if (next >= 10000) {
			next %= 10000;
		}
		if (!check[next]) {
			
			q.push({ next, res + "D" });
			check[next] = true;
		}

		next = num - 1;
		if (next < 0) {
			next = 9999;
		}
		if (!check[next]) {
			q.push({ next, res + "S" });
			check[next] = true;
		}

		next = (num % 1000) * 10 + (num / 1000);
		if (!check[next]) {
			q.push({ next, res + "L" });
			check[next] = true;
		}

		next = (num % 10) * 1000 + (num / 10);
		if (!check[next]) {
			q.push({ next, res + "R" });
			check[next] = true;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		bfs(a, b);
		memset(check, false, sizeof(check));
	}
	return 0;
}