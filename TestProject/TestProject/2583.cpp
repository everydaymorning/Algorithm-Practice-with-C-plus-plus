#include <bits/stdc++.h>

using namespace std;


int paper[102][102];
char vis[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int num = 0;
int main() {
	int n, m, k;
	cin >> n >> m >> k;

	queue<pair<int, int>> q;
	vector<int> v;
	for (int i = 0; i < k; i++) {
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;

		for (int j = ay; j < by; j++) {
			for (int l = ax; l < bx; l++) {
				paper[j][l] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] != 0 || vis[i][j]) continue;

			vis[i][j] = 1;
			q.push(make_pair(i, j));
			int area = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (paper[nx][ny] != 0 || vis[nx][ny]) continue;

					q.push(make_pair(nx, ny));
					vis[nx][ny] = 1;
					area++;

				}
			}
			v.push_back(area);
			num++;
		}
		
	}

	sort(v.begin(), v.end());
	int v_size = v.size();
	cout << num << '\n';

	for (int i = 0; i < v_size; i++) {
		cout << v.at(i) << " ";
	}

	return 0;
}