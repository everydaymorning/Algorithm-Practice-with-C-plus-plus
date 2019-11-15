#include <bits/stdc++.h>
using namespace std;

string board[27];
bool vis[27][27];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	
	int num_danji = 0;
	int num_house = 0;
	
	vector<int> v;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != '1' || vis[i][j]) continue;
			int house = 1;
			queue<pair<int, int>> q;
			
			vis[i][j] = 1;

			q.push(make_pair(i, j));

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != '1' || vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					house++;

					cout << "nx: " << nx << "     ny: " << ny << "      house: " << house << '\n';

				}
			}
			
			v.push_back(house);
			num_danji++;
		}
	}

	sort(v.begin(), v.end());

	cout << num_danji << '\n';
	int v_size = v.size();
	for (int i = 0; i < v_size; i++) {
		cout << v.at(i) << '\n';
	}


	return 0;
}