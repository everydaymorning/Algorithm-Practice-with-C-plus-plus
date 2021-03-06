#include <bits/stdc++.h>
using namespace std;

int n, k, L, x;
char c;
int MAP[101][101];
bool check[101][101];

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int cnt;
vector<pair<int, char>> v;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		MAP[a - 1][b - 1] = 1; // 1은 사과
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> x >> c;
		v.push_back({ x,c });
	}
	deque<pair<int, int>> dq;
	MAP[0][0] = 2;
	dq.push_back({ 0,0 });
	int x = 0;
	int y = 0;
	int d = 0;
	int idx = 0;
	while (1) {
		cnt++;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || MAP[nx][ny] == 2) {
			cout << cnt;
			break;
		}
		if (MAP[nx][ny] == 1) {
			MAP[nx][ny] = 2;
			dq.push_front({ nx,ny }); // 뱀의 머리 설정

		}
		else if(MAP[nx][ny] == 0){
			MAP[nx][ny] = 2;
			dq.push_front({ nx,ny }); // 뱀의 머리 설정
			MAP[dq.back().first][dq.back().second] = 0; // 꼬리 자르기
			dq.pop_back();
		}

		if (idx < v.size()) {
			if (cnt == v[idx].first) {
				if (v[idx].second == 'L') {
					d = (d + 1) % 4; // 왼쪽으로 회전
				}
				else {
					d = (d + 3) % 4; // 오른쪽으로 회전
				}
				idx++;

			}
		}
		x = nx;
		y = ny;

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << MAP[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/
	}
	return 0;
}