#include <bits/stdc++.h>
using namespace std;
int n, m, MIN_ROW, MIN_COL, MAX_SUM;
int MAP[101][101];
bool check[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<pair<int, int>, int>> v;
bool cmp(pair<pair<int, int>, int > p1, pair<pair<int, int>, int> p2) {
	if (p1.second == p2.second) {
		if (p1.first.first == p2.first.first) return p1.first.second < p2.first.second;
	}
	return p1.second > p2.second;
}
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	check[a][b] = true;
	int sum = MAP[a][b];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < a || ny < b || nx > a + 2 || ny > b + 2) continue;
			if (check[nx][ny]) continue;
			q.push({ nx,ny });
			check[nx][ny] = true;
			sum += MAP[nx][ny];
		}
	}
	v.push_back({ {a+1,b+1},sum });

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			bfs(i, j);
			memset(check, false, sizeof(check));
		}
	}

	sort(v.begin(), v.end(), cmp);

	cout << v[0].second << '\n';
	cout << v[0].first.first << " " << v[0].first.second;
	return 0;
}