#include <bits/stdc++.h>
using namespace std;
vector<int> lis;
int arr[501];
vector<pair<int, int>> p;
int cnt;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p.push_back({ a,b });
	}
	sort(p.begin(), p.end());
	lis.push_back(p[0].second);

	for (int i = 1; i < n; i++) {
		if (lis.back() < p[i].second) {
			lis.push_back(p[i].second);
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), p[i].second) - lis.begin();
			lis[idx] = p[i].second;
			//cout << "lis: " << lis.back() << " idx: " << idx << " p : " << p[i].second << '\n';
			cnt++;
		}
	}
	/*for (int i = 0; i < p.size(); i++) {
		cout << p[i].first << "  " << p[i].second << '\n';
	}*/
	cout << cnt;
	return 0;
}