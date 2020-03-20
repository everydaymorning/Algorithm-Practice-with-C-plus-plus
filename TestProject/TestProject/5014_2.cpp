#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;
bool check[1000001];
void bfs() {
	queue<pair<int, int>> q;
	q.push({ S,0 });
	check[S] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == G) {
			cout << cnt;
			return;
		}
		int next = cur + U;
		if (next <= F && !check[next]) {
			q.push({ next, cnt + 1 });
			check[next] = true;
		}

		next = cur - D;
		if (next > 0 && !check[next]) {
			q.push({ next, cnt + 1 });
			check[next] = true;
		}

	}
	cout << "use the stairs";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> F >> S >> G >> U >> D;

	bfs();
	return 0;
}