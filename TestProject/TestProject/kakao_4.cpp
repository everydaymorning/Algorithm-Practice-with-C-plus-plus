#include <bits/stdc++.h>
using namespace std;


int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dx1[4] = { 1,0,0,-1 };
int dy1[4] = { 0,1,-1,0 };
int MAP[26][26];
bool check[26][26];
int n;
int total = 2147483647;
bool flag;
bool flag2;
void dfs(int x, int y, int st, int cor) {
	if (x == n - 1 && y == n - 1) {
		int tmp = (st) * 100 + (cor) * 500;
		cout << "11st: " << st << "  cor: " << cor << '\n';
		total = min(tmp, total);
		flag = true;
		return;
	}
	cout << "x : " << x << " y: " << y << " st: " << st << "  cor: " << cor << '\n';
	int tmp_c = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if ((nx < 0 || ny < 0 || nx >= n || ny >= n) || check[nx][ny] || MAP[nx][ny] == 1) {
			continue;
		}
		check[nx][ny] = true;
		st += 1;
		dfs(nx, ny, st, cor);
		st -= 1;
		check[nx][ny] = false;
	}
}

int solution(vector<vector<int>> board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			MAP[i][j] = board[i][j];
		}
	}
	n = board.size();
	cout << "n: " << n << '\n';
	dfs(0, 0, 0, 0);
	memset(check, false, sizeof(check));
	//dfs1(0, 0, 0, 0, 1);
	return total;
}

int main() {
	vector<vector<int>> v = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	int ans = solution(v);
	cout << ans;
	return 0;
}