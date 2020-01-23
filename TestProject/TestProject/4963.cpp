#include <bits/stdc++.h>
using namespace std;


int dx[8] = { -1,0,1,0,-1,1,-1,1};
int dy[8] = { 0,1,0,-1,-1,-1,1,1};
bool check[51][51];
int arr[51][51];
int cnt;
void bfs(int b,int a,int s, int e) {
	if (arr[b][a] == 0 || check[b][a]) return;
	queue<pair<int, int>> q;
	q.push(make_pair(b, a));
	check[b][a] = true;
	
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= s || ny < 0 || ny >= e) continue;
			if (check[nx][ny] || arr[nx][ny] == 0) continue;
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
			//cout << "nx: " << nx << "   ny: " << ny  << "    arr[nx][ny]: " << arr[nx][ny] << '\n';
			//cout << "dir: " << dir << '\n';
		}
	}
	cnt++;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		memset(check, false, sizeof(check));
		memset(arr, 0, sizeof(arr));
		cnt = 0;
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				bfs(i, j, b, a);
				
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}