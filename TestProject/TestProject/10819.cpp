#include <bits/stdc++.h>
using namespace std;

int n, res;
int arr[9];
vector<int> v;
bool check[9];
void dfs(int s) {
	if (s == n) {
		int sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		res = max(res, sum);
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		v.push_back(arr[i]);
		dfs(s + 1);
		v.pop_back();
		check[i] = false;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0);

	cout << res;
	return 0;
}