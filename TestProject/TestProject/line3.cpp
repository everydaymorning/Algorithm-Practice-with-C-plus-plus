#include <bits/stdc++.h>
using namespace std;
bool check[300001];
int n;
string road;
int MAX = 0;
//이분탐색으로 다시 풀어보기
void dfs(int cnt, int idx) {
	if (cnt == n) {
		int num = 0;
		for (int i = 0; i < road.size(); i++) {
			if (road[i] == '1') {
				num++;
			}
			else {
				MAX = max(MAX, num);
				num = 0;
			}
		}
		return;
	}
	
	for (int i = idx; i < road.size(); i++) {
		if (check[i]) continue;
		if (road[i] == '1') continue;
		check[i] = true;
		road[i] = '1';
		dfs(cnt + 1, i);
		road[i] = '0';
		check[i] = false;
	}

}
int main() {
	cin >> road;
	cin >> n;
	int one = 0;
	for (int i = 0; i < road.size(); i++) {
		if (road[i] == '0') one++;
	}
	if (one <= n) {
		cout << road.size();
	}
	else {
		dfs(0, 0);
		cout << MAX;
	}
	return 0;
}