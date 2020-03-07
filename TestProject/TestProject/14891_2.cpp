#include <bits/stdc++.h>
using namespace std;
int k;
int MAP[4][8];
bool check[4];
deque<int> dq[4];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			dq[i].push_back(str[j] - '0');
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		memset(check, false, sizeof(check));
		int num, d;
		cin >> num >> d;

		num -= 1;
		queue<pair<int, int>> q;
		vector<pair<int, int>> v;
		v.push_back({ num,d });
		q.push({ num, d });

		check[num] = true;
		while (!q.empty()) {
			int cur_num = q.front().first;
			int cur_d = q.front().second;
			q.pop();

			if (cur_num != 0) {
				if (dq[cur_num - 1][2] != dq[cur_num][6] && !check[cur_num - 1]) {
					q.push({ cur_num - 1, cur_d * -1 });
					v.push_back({ cur_num - 1, cur_d * -1 });
					check[cur_num - 1] = true;
				}
			}
			if (cur_num != 3) {
				if (dq[cur_num][2] != dq[cur_num + 1][6] && !check[cur_num + 1]) {
					q.push({ cur_num + 1, cur_d * -1 });
					v.push_back({ cur_num + 1, cur_d * -1 });
					check[cur_num + 1] = true;
				}
			}
		}

		for (int j = 0; j < v.size(); j++) {
			int cur_num = v[j].first;
			int cur_d = v[j].second;

			if (cur_d == 1) {
				int tmp = dq[cur_num].back();
				dq[cur_num].pop_back();
				dq[cur_num].push_front(tmp);
			}
			else {
				int tmp = dq[cur_num].front();
				dq[cur_num].pop_front();
				dq[cur_num].push_back(tmp);
			}
		}
	}

	int cnt = 0;
	if (dq[0][0] == 1) cnt += 1;
	if (dq[1][0] == 1) cnt += 2;
	if (dq[2][0] == 1) cnt += 4;
	if (dq[3][0] == 1) cnt += 8;
	cout << cnt;

	return 0;
}