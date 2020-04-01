#include <bits/stdc++.h>

using namespace std;
int MIN = 9;
void dfs(int n, int num, int cnt, int sum) {
	if (cnt >= 9) {
		return;
	}

	if (num == sum) {
		MIN = min(MIN, cnt);
		return;
	}
	int tmp = 0;
	for (int i = 1; i <= 9; i++) {
		tmp = tmp * 10 + n;
		dfs(n, num, cnt + i, sum + tmp);
		dfs(n, num, cnt + i, sum - tmp);
		
		if (num != 0) {
			dfs(n, num, cnt + i, sum * tmp);
			dfs(n, num, cnt + i, sum / tmp);
		}
	}

}
int main() {
	int n, number;

	cin >> n >> number;

	dfs(n, number, 0, 0);

	cout << MIN;
	return 0;
}