#include <bits/stdc++.h>
using namespace std;
int arr[6][6];
int ans;
bool check[1000001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int a, int b, int sum, int cnt) {
	if (cnt == 5) {
		
		if (!check[sum]) {
			ans++;
			check[sum] = true;
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = a + dx[dir];
		int ny = b + dy[dir];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		int tmp = arr[nx][ny];
		dfs(nx, ny, sum * 10 + tmp, cnt + 1);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, arr[i][j], 0);
		}
	}
	cout << ans;
	return 0;
}