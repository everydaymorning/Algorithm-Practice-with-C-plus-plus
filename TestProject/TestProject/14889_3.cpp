#include <bits/stdc++.h>
using namespace std;
int n;
int MAP[21][21];
vector<int> start;
vector<int> link;
int MIN = 2147483647;
void dfs(int cnt) {
	if (cnt == n) {
		if (start.size() == link.size()) {

			int tmp_sum = 0;
			for (int i = 0; i < start.size() - 1; i++) {
				for (int j = i + 1; j < start.size(); j++) {
					tmp_sum += MAP[start[i]][start[j]] + MAP[start[j]][start[i]];
				}
			}

			int tmp_sum1 = 0;
			for (int i = 0; i < link.size() - 1; i++) {
				for (int j = i + 1; j < link.size(); j++) {
					tmp_sum1 += MAP[link[i]][link[j]] + MAP[link[j]][link[i]];
				}
			}

			int total = abs(tmp_sum1 - tmp_sum);
			MIN = min(MIN, total);
		}

		return;
	}

	start.push_back(cnt);
	dfs(cnt + 1);
	start.pop_back();

	link.push_back(cnt);
	dfs(cnt + 1);
	link.pop_back();
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}

	dfs(0);
	cout << MIN;
	return 0;
}