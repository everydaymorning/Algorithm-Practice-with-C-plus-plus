#include <bits/stdc++.h>
using namespace std;
int n;
int op1, op2, op3, op4;
vector<int> v;
int MIN = 1000000000;
int MAX = -1000000000;
void dfs(int cnt, int sum, int idx) {
	if (cnt == n - 1) {
		MIN = min(sum, MIN);
		MAX = max(sum, MAX);
		return;
	}

	if (op1 > 0) {
		op1--;
		dfs(cnt + 1, sum + v[idx], idx + 1);
		op1++;
	}

	if (op2 > 0) {
		op2--;
		dfs(cnt + 1, sum - v[idx], idx + 1);
		op2++;
	}

	if (op3 > 0) {
		op3--;
		dfs(cnt + 1, sum * v[idx], idx + 1);
		op3++;
	}

	if (op4 > 0) {
		op4--;
		dfs(cnt + 1, (int)sum / v[idx], idx + 1);
		op4++;
	}
	
	
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> op1 >> op2 >> op3 >> op4;
	
	dfs(0, v[0], 1);
	cout << MAX << '\n' << MIN;
	return 0;
}