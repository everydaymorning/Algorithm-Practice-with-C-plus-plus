#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int MAP[7][7];
bool check[7][7];


void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	check[a][b] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx <= 0 || ny <= 0 || nx > 6 || ny > 6) continue;
			if (check[nx][ny]) continue;
			if (MAP[nx][ny] == MAP[a][b]) {
				cnt++;
				q.push({ nx,ny });
				check[nx][ny] = true;
			}
		}
	}

	if (cnt >= 3) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				if (check[i][j]) MAP[i][j] = 0;
			}
		}

		for (int i = 1; i <= 6; i++) {
			for (int j = 6; j > 0; j--) {
				if (MAP[j][i] != 0) continue;
				for (int k = j - 1; k >= 0; k--) {
					if (MAP[k][i] == 0) continue;
					MAP[j][i] = MAP[k][i];
					MAP[k][i] = 0;
					break;
				}
			}
		}
		memset(check, false, sizeof(check));

	}
	memset(check, false, sizeof(check));

}
vector<string> solution(vector<vector<int>> macaron) {
	vector<string> answer;
	for (int i = 0; i < macaron.size(); i++) {
		int num = macaron[i][0];
		int color = macaron[i][1];
		for (int j = 6; j >= 0; j--) {
			if (MAP[j][num] == 0) {
				MAP[j][num] = color;
				break;
			}
		}


		for (int j = 1; j <= 6; j++) {
			for (int k = 1; k <= 6; k++) {
				if (MAP[j][k] == 0) continue;
				bfs(j, k);
			}
		}
	}

	for (int i = 1; i <= 6; i++) {
		string s;
		for (int j = 1; j <= 6; j++) {
			string tmp = to_string(MAP[i][j]);
			s += tmp;
		}
		answer.push_back(s);
	}

	return answer;
}

int main() {
	vector<vector<int>> v;
	vector<string> ans;
	// 열 번호, 색
	v = { {1, 1 }, { 1, 2 }, { 1, 4 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 4 }, { 3, 1 }, { 3, 2 }, { 3, 3 }, {3,4}, {4,4}, {4,3}, {5,4} ,{6,1} };
	ans = solution(v);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}