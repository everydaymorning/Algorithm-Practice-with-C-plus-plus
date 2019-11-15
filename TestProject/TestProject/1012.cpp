#include <bits/stdc++.h>
using namespace std;


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	int t;
	cin >> t;
	
	
	for (int i = 0; i < t; i++) {
		int box[52][52] = { 0 };
		bool vis[52][52] = { 0 };

		int n, m, k;
		int mx = 0;
		queue<pair<int, int>> q;
		cin >> n >> m >> k;

		for (int j = 0; j < k; j++) {
			int a, b;

			cin >> a >> b;

			box[a][b] = 1;
			
		}

		
	
		for (int w = 0; w < n; w++) {
			for (int e = 0; e < m; e++) {
				if (box[w][e] != 1 || vis[w][e]) continue;

				vis[w][e] = 1;

				q.push(make_pair(w, e));

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (box[nx][ny] != 1 || vis[nx][ny]) continue;

						vis[nx][ny] = 1;
						q.push(make_pair(nx, ny));

						
					}
					
				}
				mx++;

			}
			
		}

		cout << mx << '\n';
	}
	

	return 0;

}