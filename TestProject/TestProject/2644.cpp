#include <bits/stdc++.h>
using namespace std;
int n, m;
int node1, node2;
vector<int> v[101];
bool check[101];
int res[101];
int bfs() {
	queue<int> q;
	q.push(node1); // node1를 넣어줌

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == node2) { // 현재 큐가 node2와 같다면
			return res[node2];
		}
		
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x].at(i);
			if (res[nx] == 0) { // 방문하지 않았다면
				q.push(nx); 
				res[nx] = res[x] + 1;
			}
		}
	}
	return -1; // 연결되어 있지 않으면 -1
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> node1 >> node2;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cout << bfs();
	return 0;

}