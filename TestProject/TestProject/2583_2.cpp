#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
bool check[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, t;
int cnt;
vector<int> v;

void bfs(int i, int j) {
	if (check[i][j] && arr[i][j] == 1) return;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;
	arr[i][j] = 1;
	cnt++;
	int area = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (arr[nx][ny] == 1 && check[nx][ny]) continue;
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			arr[nx][ny] = 1;
			area++;
		}
	}
	v.push_back(area);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> t;

	while (t--) {
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;

		for (int i = y; i < yy; i++) {
			for (int j = x; j < xx; j++) {
				arr[i][j] = 1;
				check[i][j] = true;
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bfs(i, j);
		}
	}
	sort(v.begin(), v.end());

	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}