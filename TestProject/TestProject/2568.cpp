#include <bits/stdc++.h>
using namespace std;
vector<int> lis;
vector<pair<int, int>> v;
vector<pair<int, int>> ans;
int cnt, n;
bool check[500001];
stack<int> s;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		check[a] = true;
	}
	sort(v.begin(), v.end());
	int j = 0;
	lis.push_back(v[0].second);

	ans.push_back({ 0, v[0].first });
	
	for (int i = 1; i < n; i++) {
		if (lis.back() < v[i].second) {
			lis.push_back(v[i].second);
			ans.push_back({ ++j, v[i].first });
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();
			lis[idx] = v[i].second;
			ans.push_back({ idx, v[i].first });
			cnt++;
		}
	}

	cout << cnt << '\n';

	int tmp = lis.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (ans[i].first == tmp) {
			s.push(ans[i].second);
			tmp--;
		}
	}

	while (!s.empty()) {
		check[s.top()] = false;
		s.pop();
	}

	for (int i = 0; i < 500001; i++) {
		if (check[i]) cout << i << '\n';
	}
	return 0;
}