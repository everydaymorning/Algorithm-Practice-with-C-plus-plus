#include <bits/stdc++.h>
using namespace std;
int g[101][101];
int res[101][101];
bool check[101];
int n;
void dfs(int s) {
	for (int j = 0; j < n; j++) {
		if (g[s][j] == 1 && !check[j]) {
			check[j] = true;
			dfs(j);
		}
	}

}

void printf() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j] << " ";
		}
		cout << '\n';
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		memset(check, false, sizeof(check));
		dfs(i);

		for (int j = 0; j < n; j++) {
			if (check[j]) g[i][j] = 1;
		}
	}

	printf();
	return 0;

}