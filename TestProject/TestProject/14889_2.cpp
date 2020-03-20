#include <bits/stdc++.h>
using namespace std;
int n;
int MAP[21][21];
vector<int> start, link;
int MIN = 987654321;
void dfs(int idx) {
	if (idx == n) {
		if (start.size() == link.size()) {
			int startSum = 0;
			for (int i = 0; i < start.size() - 1; i++) {
				for (int j = i + 1; j < start.size(); j++) {
					startSum += MAP[start[i]][start[j]] + MAP[start[j]][start[i]];
				}
			}
			int linkSum = 0;
			for (int i = 0; i < link.size() - 1; i++) {
				for (int j = i + 1; j < link.size(); j++) {
					linkSum += MAP[link[i]][link[j]] + MAP[link[j]][link[i]];
				}
			}
			int Sum = abs(startSum - linkSum);
			MIN = min(Sum, MIN);

		}
		return;
	}

	start.push_back(idx);
	dfs(idx + 1);
	start.pop_back();

	link.push_back(idx);
	dfs(idx + 1);
	link.pop_back();

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

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