#include <bits/stdc++.h>
using namespace std;
int r, c, t, cnt;
int MAP[41][41];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> MAP[i][j];
		}
	}
	cin >> t;
	vector<int> v, res;
	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 3; l++) {
					v.push_back(MAP[k][l]);
				}
			}
			sort(v.begin(), v.end());
			res.push_back(v[4]);
			v.clear();
		}
	}
	
	for (int i = 0; i < res.size(); i++) {
		if (res[i] >= t) cnt++;
	}
	cout << cnt;
	return 0;
}