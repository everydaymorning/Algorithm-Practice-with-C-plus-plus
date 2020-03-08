#include <bits/stdc++.h>
using namespace std;
bool check[100001];
int n, k;
void bfs() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,n });
	check[n] = true;

	while (!q.empty()) {
		int sec = q.top().first;
		int cur = q.top().second;
		q.pop();
		//cout << "cur: " << cur << "  sec: " << sec << '\n';

		if (cur == k) {
			cout << sec;
			return;
		}

		if (cur * 2 <= 100000 && !check[cur * 2]) {
			q.push({ sec, cur * 2 });
			check[cur * 2] = true;
		}

		if (cur - 1 >= 0 && !check[cur - 1]) {
			q.push({ sec + 1, cur - 1});
			check[cur - 1] = true;

		}
		if (cur + 1 <= 100000 && !check[cur + 1]) {
			q.push({ sec + 1, cur + 1 });
			check[cur + 1] = true;

		}


		
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	bfs();
	return 0;
}