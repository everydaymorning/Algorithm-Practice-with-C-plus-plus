#include <bits/stdc++.h>
using namespace std;
int n;
int COL[16];

int res;

bool possible(int idx) {
	for (int i = 1; i < idx; i++) {

		if (COL[i] == COL[idx]) return false; // i행과 idx행의 열 값이 같은 경우 = 같은 열에 있는 경우 

		if(abs(i-idx) == abs(COL[i] - COL[idx])) return false; // 대각선에 있는 경우
	}

	return true;
}
void dfs(int idx) {
	if (idx == n) {
		res++;
	}

	for (int i = 1; i <= n; i++) {
		COL[idx + 1] = i;
		if (possible(idx + 1)) dfs(idx + 1);
	}

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		COL[1] = i; // 1행 i열

		dfs(1);
	}
	cout << res;
	return 0;
}