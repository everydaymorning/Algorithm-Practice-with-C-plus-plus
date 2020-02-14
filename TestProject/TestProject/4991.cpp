#include <bits/stdc++.h>
using namespace std;
int w, h, s_x, s_y, d_x, d_y;
int MAP[21][21];
int dist[21][21];
bool check[21][21];
bool visit[11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int MIN = 2147483647;
bool flag2;
vector<int> vv;
void bfs(int a, int b, int num) {
	memset(check, false, sizeof(check));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b}, 0 });
	check[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		//cout << "x: " << x << " y: " << y << " d: " << d << '\n';
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 1 || ny < 1 || nx > h || ny > w) continue;
			if (MAP[nx][ny] == -1 || check[nx][ny]) continue;
			if (MAP[nx][ny] > num) {
				int tmp = MAP[nx][ny];
				dist[num][tmp] = d + 1;
				dist[tmp][num] = d + 1;
				//cout << "nx: " << nx << "  ny: " << ny << " d: " << d << " num: " << num << " tmp: " << tmp << '\n';
			}
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}
	}
}

void P(int s, int cnt) {
	if (s == cnt) {
		int sum = dist[0][vv[0]];
		if (sum == 0) flag2 = true;
		for (int j = 0; j < cnt - 1; j++) {
			sum += dist[vv[j]][vv[j + 1]];
			if (dist[vv[j]][vv[j + 1]] == 0) flag2 = true;
		}

		MIN = min(MIN, sum);
		return;
	}

	for (int i = 0; i < cnt; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		vv.push_back(i + 1);
		P(s + 1, cnt);
		vv.pop_back();
		visit[i] = false;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (1) {
		memset(dist, 0, sizeof(dist));
		memset(MAP, 0, sizeof(MAP));
		cin >> w >> h;
		int cnt = 0;
		if (w == 0 && h == 0) break;
		queue<pair<int, int>> trash;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				char ch;
				cin >> ch;
				if (ch == 'o') {
					s_x = i; s_y = j;
				}
				else if (ch == 'x') {
					MAP[i][j] = -1;
				}
				else if (ch == '*') {
					MAP[i][j] = ++cnt;
					trash.push({ i,j });
				}
			}
		}
		bfs(s_x, s_y, 0);
		for (int i = 1; i <= cnt; i++) {
			int x = trash.front().first;
			int y = trash.front().second;
			bfs(x, y, i);
			trash.pop();
		}
		
		/*vector<int> v;
		for (int i = 1; i <= cnt; i++) {
			v.push_back(i);
		}*/
		//bool flag = false;
		/*int MIN = 2147483647;
		do {
			int sum = dist[0][v[0]];
			cout << "sum: " << sum << " ";
			if (sum == 0) flag = true;
			for (int i = 0; i < cnt-1; i++) {
				sum += dist[v[i]][v[i + 1]];
				cout << "dist: " << dist[v[i]][v[i + 1]] << " " << '\n';
				cout << v[i] << " " << v[i + 1] << " " << '\n';
				if (dist[v[i]][v[i+1]] == 0) flag = true;
			}
			cout << '\n';
			cout << "sum: " << sum << '\n';
			MIN = min(MIN, sum);
		} while (next_permutation(v.begin(), v.end()));*/
		P(0, cnt);
		if (flag2) cout << "-1" << '\n';
		else cout << MIN << '\n';

		flag2 = false;
		MIN = 2147483647;
	}
	return 0;
}