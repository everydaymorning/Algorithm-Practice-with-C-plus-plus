#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int cnt;
void hanoi(int n, int from, int mid, int to) {
	if (n == 1) {
		v.push_back(make_pair(from, to));
		cnt++;
	}
	else {
		hanoi(n - 1, from, to, mid);
		v.push_back(make_pair(from, to));
		cnt++;
		hanoi(n - 1, mid, from, to);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	hanoi(n,1,2,3);
	
	cout << cnt << '\n';
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
	
}