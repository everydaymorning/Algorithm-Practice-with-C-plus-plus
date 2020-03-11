#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int t;
int cnt;
void dfs(int idx, int sum) {
	if (idx == v.size()) {
		if (sum == t) cnt++;
		return;
	}

	dfs(idx + 1, sum + v[idx]);
	dfs(idx + 1, sum + v[idx] * -1);
}
int main() {
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	cin >> t;
	dfs(0,0);
	cout << cnt;
	return 0;
}