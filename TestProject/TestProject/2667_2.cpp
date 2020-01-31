#include <bits/stdc++.h>
using namespace std;
string MAP[26];
bool check[26][26];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt;
int n;

vector<int> v;

void bfs(int a, int b) {
	if (MAP[a][b] == '0' || check[a][b]) return;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	check[a][b] = true;
	cnt++;
	int area = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (MAP[nx][ny] == '0') continue;
			if (check[nx][ny]) continue;
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			area++;
		}
	}
	v.push_back(area);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> MAP[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bfs(i, j);
		}
	}

	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}