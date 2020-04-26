#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v, tmp;
vector<pair<int, int>> v1[300001];
int arr[300001];
int ans;
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		tmp.push_back({ x,y });
	}

	for (int i = 0; i < tmp.size(); i++) {
		int t = tmp[i].second;
		for (int j = 1; j <= n; j++) {
			if (arr[j] == t) {
				arr[j] = tmp[i].first;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[j] == i) {
				v1[i].push_back(v[j-1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v1[i].size() == 0) continue;
		int max_x = 0;
		int max_y = 0;
		int min_x = 2147483647;
		int min_y = 2147483647;
		for (int j = 0; j < v1[i].size(); j++) {
			max_x = max(v1[i][j].first, max_x);
			max_y = max(v1[i][j].second, max_y);
			min_x = min(v1[i][j].first, min_x);
			min_y = min(v1[i][j].second, min_y);
		}
		int total = (abs(max_x - min_x) + abs(max_y - min_y)) * 2;
		ans = max(ans, total);
	}
	cout << ans;
	return 0;
}