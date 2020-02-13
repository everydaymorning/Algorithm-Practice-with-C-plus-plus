#include <bits/stdc++.h>
using namespace std;
int n, k;
bool check[100001];
int cnt;
void bfs() {
	queue<pair<int, int>> q;
	q.push({ n,0 });
	check[n] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (x == k) {
			cnt = dist;
			return;
		}
		int nx = x + 1;
		if (nx <= 100000 && !check[nx]) {
			q.push({ nx, dist + 1 });
			check[nx] = true;
		}

		nx = x - 1;
		if (nx >= 0 && !check[nx]) {
			q.push({ nx, dist + 1 });
			check[nx] = true;
		}
		nx = 2 * x;
		if (nx <= 100000 && !check[nx]) {
			q.push({ nx, dist + 1 });
			check[nx] = true;
		}

	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	bfs();
	cout << cnt;
	return 0;
}