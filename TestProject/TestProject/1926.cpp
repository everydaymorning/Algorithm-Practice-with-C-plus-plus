#include <bits/stdc++.h>

using namespace std;

int board[502][502]; // 그림을 표시하기 위한 변수
bool vis[502][502]; // 해당 칸에 방문했는지 표시하기 위한 변수
int dx[4] = { 1,0,-1,0 }; 
int dy[4] = { 0,1,0,-1 }; // 상하좌우를 위한 변수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m; // 그림 크기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int mx = 0; // 그림의 최대값
	int num = 0; // 그림의 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue; // 그림이 아니거나 방문한 경우는 넘어감

			num++; // 그림의 개수 증가
			queue<pair<int, int>> q;
			vis[i][j] = 1; // 해당 칸에 방문했다는 표시
			q.push(make_pair(i, j)); // 해당 칸을 큐에 삽입

			int area = 0; // 그림의 넓이를 비교하기 위한 변수
			while (!q.empty()) {
				area++; // 그림의 넓이 증가
				auto cur = q.front(); // 큐의 첫번째 원소를 cur에 대입
				q.pop(); // 큐의 원소 삭제
				for (int dir = 0; dir < 4; dir++) { // 현재 위치의 상하좌우 변수를 검사하기 위한 반복문
					int nx = cur.first + dx[dir]; 
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 배열의 범위를 벗어나면 넘어감
					if (vis[nx][ny] || board[nx][ny] != 1) continue; // 배열의 범위가 벗어나지 않고 해당 칸이 방문했거나 그림이 아니면 넘어감
					vis[nx][ny] = 1; // 해당 칸은 방문했다고 표시
					q.push(make_pair(nx, ny)); // 방문하지 않고 그림인 곳을 큐에 삽입
				}
			}
			mx = max(mx, area); // STL 함수 , area가 mx보다 크면 mx에 area 삽입
		}
	}

	cout << num << '\n' << mx << '\n'; // 그림의 개수와 최대 넓이 출력
	return 0;
}