#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt;
int MAP[11][11];
int yang[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
deque<int> tree[11][11];
queue<int> dead[11][11];

void spring() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t = tree[i][j].size();
			
			while(t--) {
				int age = tree[i][j].front();
				tree[i][j].pop_front();
				if (MAP[i][j] >= age) {
					tree[i][j].push_back(age + 1);
					MAP[i][j] -= age;
				}
				else {
					dead[i][j].push(age);
				}

			}
		}
	}
	
}

void summer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t = dead[i][j].size();

			while(t--) {
				int age = dead[i][j].front();
				age /= 2;
				dead[i][j].pop();
				MAP[i][j] += age;
			}
		}
	}
}

void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t = tree[i][j].size();

			for (int k = 0; k < t; k++) {
				if (tree[i][j][k] % 5 != 0) continue;
				
				for (int dir = 0; dir < 8; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 1 || ny < 1 || nx > n || ny > n) continue;

					tree[nx][ny].push_front(1);
				}
				
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			MAP[i][j] += yang[i][j];
		}
	}
}

void countTree() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t = tree[i][j].size();
			cnt += t;

		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			MAP[i][j] = 5;
			cin >> yang[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
	
	while (k--) {
		spring();
		summer();
		fall();
		winter();
	}
	countTree();
	cout << cnt;
	return 0;
}