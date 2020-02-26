#include <bits/stdc++.h>
using namespace std;
int n;
int MAP[21][21];
bool check[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Shark {
	int x;
	int y;
	int size;
	int eat_cnt;
	int time;
};

struct Fish {
	int x;
	int y;
	int dist;
};

Shark s;
vector<Fish> fish;

bool cmp(Fish a, Fish b) {
	if (a.dist <= b.dist) {
		if (a.dist == b.dist) {
			if (a.x <= b.x) {
				if (a.x == b.x) {
					if (a.y < b.y) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
void bfs(int a, int b) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b},0 });
	check[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny]) continue;
			if (MAP[nx][ny] == 0 || MAP[nx][ny] == s.size) {
				check[nx][ny] = true;
				q.push({ {nx,ny},d + 1 });
			}
			else if (MAP[nx][ny] < s.size) {
				Fish tmp;
				tmp.x = nx;
				tmp.y = ny;
				tmp.dist = d + 1;
				fish.push_back(tmp);
				check[nx][ny] = true;
				q.push({ {nx,ny},d + 1 });
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				s.x = i;
				s.y = j;
				s.size = 2;
				s.eat_cnt = 0;
				s.time = 0;
			}
		}
	}

	while (1) {
		fish.clear();
		memset(check, false, sizeof(check));

		bfs(s.x, s.y);
		if (fish.size() == 0) {
			cout << s.time;
			break;
		}
		else if (fish.size() == 1) {
			MAP[fish[0].x][fish[0].y] = 9;
			MAP[s.x][s.y] = 0;
			s.eat_cnt++;
			s.x = fish[0].x;
			s.y = fish[0].y;
			s.time += fish[0].dist;

			if (s.eat_cnt == s.size) {
				s.eat_cnt = 0;
				s.size++;
			}
			/*cout << "size = 1" << "  x: " << fish[0].x << "  y: " << fish[0].y << "  dist: " << fish[0].dist << '\n';

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << MAP[i][j] << " ";
				}
				cout << '\n';
			}*/
		}
		else {
			sort(fish.begin(), fish.end(), cmp);
			/*for (int k = 0; k < fish.size(); k++) {
				cout << "size > 1 " << "  x: " << fish[k].x << "  y: " << fish[k].y << "  dist: " << fish[k].dist << '\n';
			}*/
			MAP[fish[0].x][fish[0].y] = 9;
			MAP[s.x][s.y] = 0;
			s.eat_cnt++;
			s.x = fish[0].x;
			s.y = fish[0].y;
			s.time += fish[0].dist;

			if (s.eat_cnt == s.size) {
				s.eat_cnt = 0;
				s.size++;
			}

			/*for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << MAP[i][j] << " ";
				}
				cout << '\n';
			}*/
		}
	}
	return 0;
}