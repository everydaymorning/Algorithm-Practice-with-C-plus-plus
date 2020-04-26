#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < v.size(); i++) {
		int cnt = 0;
		int x = v[i].first;
		int y = v[i].second;
		for (int j = 0 ; j < v.size(); j++) {
			if (i == j) continue;
			int nx = v[j].first;
			int ny = v[j].second;
			if (x > nx && ny > x) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}