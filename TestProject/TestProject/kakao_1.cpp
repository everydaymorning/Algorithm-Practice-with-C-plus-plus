#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int MAP[5][4] = { {1,2,3},{4,5,6},{7,8,9},{-1,0,-1} };

vector<int> num;
bool check[5][4];
struct left_hand {
	int x;
	int y;
};

struct right_hand {
	int x;
	int y;
};

left_hand lh;
right_hand rh;
int bfs_left(int a, int b, int idx) {
	queue<pair<pair<int, int>, int>> LEFT;

	LEFT.push({ {a,b}, 0 });
	check[a][b] = true;
	while (!LEFT.empty()) {
		int x = LEFT.front().first.first;
		int y = LEFT.front().first.second;
		int cnt = LEFT.front().second;
		LEFT.pop();

		if (MAP[x][y] == idx) {
			lh.x = x;
			lh.y = y;
			cout << "val: " << MAP[x][y] << "  num: " << idx << '\n';
			cout << "left x: " << lh.x << "  left y: " << lh.y << " cnt: " << cnt << '\n';
			return cnt;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 3) continue;
			if (check[nx][ny] || MAP[nx][ny] == -1) continue;
			cout << "left nx: " << nx << "  left ny: " << ny << '\n';
			LEFT.push({ {nx,ny}, cnt + 1 });
			check[nx][ny] = true;
		}
	}
	return 0;
}
int bfs_right(int a, int b, int idx) {
	queue<pair<pair<int, int>, int>> RIGHT;
	RIGHT.push({ {a,b},0 });
	check[a][b] = true;
	while (!RIGHT.empty()) {
		int x = RIGHT.front().first.first;
		int y = RIGHT.front().first.second;
		int cnt = RIGHT.front().second;
		RIGHT.pop();

		if (MAP[x][y] == idx) {
			rh.x = x;
			rh.y = y;
			cout << "val: " << MAP[x][y] << "  num: " << idx << '\n';

			cout << "right x: " << rh.x << "  right y: " << rh.y << " cnt: " << cnt << '\n';

			return cnt;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 3) continue;
			if (check[nx][ny] || MAP[nx][ny] == -1) continue;
			cout << "right nx: " << nx << "  right ny: " << ny << '\n';

			RIGHT.push({ {nx,ny}, cnt + 1 });
			check[nx][ny] = true;
		}
	}
	return 0;
}
string solution(vector<int> numbers, string hand) {
	num = numbers;
	string answer = "";
	lh.x = 3;
	lh.y = 0;
	rh.x = 3;
	rh.y = 2;

	for (int i = 0; i < num.size(); i++) {
		if (num[i] == 1 || num[i] == 4 || num[i] == 7) {
			int tmp = bfs_left(lh.x, lh.y, num[i]);
			memset(check, false, sizeof(check));
			answer += "L";
		}
		else if (num[i] == 3 || num[i] == 6 || num[i] == 9) {
			int tmp = bfs_right(rh.x, rh.y, num[i]);

			memset(check, false, sizeof(check));
			answer += "R";
		}
		else if (num[i] == 2 || num[i] == 5 || num[i] == 8 || num[i] == 0) {
			int tmp_lhx = lh.x;
			int tmp_lhy = lh.y;
			int tmp_rhx = rh.x;
			int tmp_rhy = rh.y;
			int tmp1 = bfs_left(lh.x, lh.y, num[i]);
			memset(check, false, sizeof(check));
			int tmp2 = bfs_right(rh.x, rh.y, num[i]);
			memset(check, false, sizeof(check));
			//cout << "numbers: " << num[i] << '\n';

			if (tmp1 < tmp2) {
				rh.x = tmp_rhx;
				rh.y = tmp_rhy;
				answer += "L";
			}
			else if (tmp1 > tmp2) {
				lh.x = tmp_lhx;
				lh.y = tmp_lhy;
				answer += "R";
			}
			else if (tmp1 == tmp2) {
				if (hand == "left") {
					rh.x = tmp_rhx;
					rh.y = tmp_rhy;
					answer += "L";
				}
				else if (hand == "right") {
					lh.x = tmp_lhx;
					lh.y = tmp_lhy;
					answer += "R";
				}
			}
		}
	}
	return answer;
}
int main() {
	vector<int> v = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
	string h = "left";
	string ans = solution(v, h);
	cout << ans;
	return 0;
}