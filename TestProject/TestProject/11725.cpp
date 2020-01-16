#include <bits/stdc++.h>
using namespace std;
#define MAX 100000 + 1
vector<int> tree[MAX];
int parent[MAX];
bool check[MAX];

void dfs(int s) {
	check[s] = true;

	for (int i = 0; i < (int)tree[s].size(); i++) {
		int next = tree[s][i];

		if (!check[next]) {
			parent[next] = s;
			dfs(next);
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);
	
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}