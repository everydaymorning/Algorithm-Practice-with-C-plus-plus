#include <bits/stdc++.h>
using namespace std;
int arr[12];
bool check[12];
int n;
int op[4];
int MAX = -2147483647;
int MIN = 2147483647;
void dfs(int cnt, int sum) {
	if (cnt == n - 1) {
		MAX = max(sum, MAX);
		MIN = min(sum, MIN);
		return;
	}

	if (op[0] != 0) {
		op[0]--;
		dfs(cnt + 1, sum + arr[cnt + 1]);
		op[0]++;
	}
	if (op[1] != 0) {
		op[1]--;
		dfs(cnt + 1, sum - arr[cnt + 1]);
		op[1]++;
	}
	if (op[2] != 0) {
		op[2]--;
		dfs(cnt + 1, sum * arr[cnt + 1]);
		op[2]++;
	}
	if (op[3] != 0) {
		op[3]--;
		dfs(cnt + 1, sum / arr[cnt + 1]);
		op[3]++;
	}
	
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	dfs(0, arr[0]);
	cout << MAX << '\n';
	cout << MIN;
	return 0;
}