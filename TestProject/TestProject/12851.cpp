#include <bits/stdc++.h>
using namespace std;
int n, k;
int cnt;
int t;
bool check[100001];
queue<pair<int, int>> q;
void bfs() {
	q.push({ n,0 });
	check[n] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		check[x] = true;
		if (t > 0 && x == k && t == y) { // 최솟값을 한 번 이상 업데이트 했고 같은 위치이고 현재 위치가 최솟값과 같으면 경우의 수 증가
			cnt++;
		}
		if (t == 0 && x == k) { // 처음 해당하는 위치를 만났을 때
			t = y;
			cnt++;
		}
		int nx = x - 1;
		if (nx >= 0 && !check[nx]) {
			q.push({ nx,y + 1 });
		}
		nx = x + 1;
		if (nx < 100001 && !check[nx]) {
			q.push({ nx, y + 1 });
		}
		nx = 2 * x;
		if (nx < 100001 && !check[nx]) {
			q.push({ nx,y + 1 });
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	bfs();
	cout << t << '\n' << cnt;
	return 0;
}