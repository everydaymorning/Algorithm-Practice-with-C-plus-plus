#include <bits/stdc++.h>
using namespace std;
int t, n;
int arr[104][2];
bool check[104];
queue<pair<int, int>> q;
bool flag;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == arr[n + 1][0] && y == arr[n + 1][1]) {
			flag = true;
			return;
		}

		for (int i = 1; i < n + 2; i++) {

			int nx = abs(x - arr[i][0]);
			int ny = abs(y - arr[i][1]);
			int num = nx + ny;
			if (check[i] || num > 1000) continue;
			check[i] = true;
			q.push({ arr[i][0], arr[i][1] });
		}

	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n + 2; i++) {
			cin >> arr[i][0] >> arr[i][1];
		}
		q.push({ arr[0][0], arr[0][1] });
		bfs();

		if (flag) cout << "happy" << '\n';
		else cout << "sad" << '\n';

		memset(check, false, sizeof(check));
		memset(arr, 0, sizeof(arr));
		while (!q.empty()) {
			q.pop();
		}
		flag = false;

	}
	return 0;
}