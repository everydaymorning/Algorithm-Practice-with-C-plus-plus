#include <bits/stdc++.h>
using namespace std;
int n;
int arr[9];
bool check[9];
vector<int> v;
void insert() {
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
}
void print() {
	for (int i = 0; i < v.size(); i++) {
		if (check[i]) {
			cout << v[i] << " ";
		}
	}
	cout << '\n';
}
void dfs(int cnt) {
	if (cnt == n) {
		print();
	}

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		v.push_back(arr[i]);
		dfs(cnt + 1);
		v.pop_back();
		check[i] = false;
	}
}

void solve() {
	insert();
	dfs(0);

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	
	solve();

	return 0;

}