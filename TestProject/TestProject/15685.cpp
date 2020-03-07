#include <bits/stdc++.h>
using namespace std;
int MAP[101][101];
int n;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

vector<int> direction;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x, y, d, gen;
		cin >> y >> x >> d >> gen;
		
		direction.clear();
		MAP[x][y] = 1;

		y = y + dy[d];
		x = x + dx[d];

		MAP[x][y] = 1;

		direction.push_back(d);

		for (int j = 0; j < gen; j++) {
			int d_size = direction.size();
			for (int k = d_size - 1; k >= 0; k--) {
				int nd = (direction[k] + 1) % 4;
				direction.push_back(nd);
				y = y + dy[nd];
				x = x + dx[nd];
				MAP[x][y] = 1;
			}
		}

	}
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (MAP[i][j] == 1 && MAP[i + 1][j] == 1 && MAP[i][j + 1] == 1 && MAP[i + 1][j + 1]) cnt++;
		}
	}

	cout << cnt;
	return 0;
}