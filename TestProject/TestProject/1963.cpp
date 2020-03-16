#include <bits/stdc++.h>
using namespace std;
int t, cur, nextN;
int arr[10001];
bool check[10001];
void bfs() {
	if (cur == nextN) {
		cout << "0" << '\n';
		return;
	}
	queue<pair<int, int>> q;
	q.push({ cur, 0 });
	check[cur] = true;

	while (!q.empty()) {
		int cur_num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur_num == nextN) {
			cout << cnt << '\n';
			return;
		}
		for (int i = 1000; i < 10000; i++) {
			if (arr[i] == 0 || check[i]) continue;
			string tmp_num = to_string(cur_num);
			string tmp_i = to_string(i);
			int c = 0;
			for (int j = 0; j < 4; j++) {
				if (tmp_num[j] == tmp_i[j]) c++;
			}
			if (c == 3) {
				q.push({ i,cnt + 1 });
				check[i] = true;
			}
		}
	}
}

void findPrime() {

	for (int i = 1; i < 10000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i < 10000; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j < 10000; j += i) {
			arr[j] = 0;
		}
	}

}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	findPrime();

	while (t--) {
		cin >> cur >> nextN;
		bfs();
		memset(check, false, sizeof(check));
	}
	return 0;
}