#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int> v[MAX];
int parent[MAX];
bool check[MAX];

void bfs(int start) {
	check[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int next = q.front();
		q.pop();

		for (int i = 0; i < (int)v[next].size(); i++) {
			int res = v[next][i];
			if (check[res]) continue;
			check[res] = true;
			parent[res] = next;
			q.push(res);
		}
	}

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	bfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}