#include <bits/stdc++.h>
using namespace std;
bool check[201];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt;
int num;
vector<vector<int>> v1;
void dfs(int idx) {
	check[idx] = true;

	for (int i = 0; i < num; i++) {
		if (check[i] || v1[idx][i] == 0) continue;
		dfs(i);
	}
}
void solution(int n, vector<vector<int>> v) {
	
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		dfs(i);
		cnt++;
	}
	cout << cnt;
}
int main() {
	int n = 3;
	vector<vector<int>> v;
	v.push_back({ 1,1,0 });
	v.push_back({ 1,1,0 });
	v.push_back({ 0,0,1 });
	num = n;
	v1 = v;
	solution(n, v);
	return 0;
}