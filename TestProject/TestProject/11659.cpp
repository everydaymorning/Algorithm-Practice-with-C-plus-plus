#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int total[100001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		total[i] = total[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << total[b] - total[a - 1] << '\n';
	}
	return 0;
}