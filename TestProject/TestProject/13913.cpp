#include <bits/stdc++.h>
using namespace std;
int n, k, t, cnt;
bool check[200001];
int arr[100001];
queue<pair<int, int>> q;
vector<int> v;
void bfs() {
	q.push({ n,0 });
	check[n] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == k) {
			t = y;
			int cur = x;
			while (cur != n) {
				v.push_back(cur);
				cur = arr[cur];
			}
			v.push_back(n);
			return;
		}
		int nx = x - 1;
		if (!check[nx] && nx >= 0) {
			q.push({ nx, y + 1 });
			check[nx] = true;
			arr[nx] = x;
		}
		nx = x + 1;
		if (!check[nx] && nx <= 100000) {
			q.push({ nx,y + 1 });
			check[nx] = true;
			arr[nx] = x;
		}
		nx = x * 2;
		if (!check[nx] && nx <= 100000) {
			q.push({ nx,y + 1 });
			check[nx] = true;
			arr[nx] = x;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	bfs();
	cout << t << '\n';
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	return 0;
}