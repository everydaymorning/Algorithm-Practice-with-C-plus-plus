#include <bits/stdc++.h>
using namespace std;
bool check[1000000000];

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	vector<int> res;
	for (int i = 0; i < 2; i++) {
		if (v[0][i] == v[1][i]) {
			res.push_back(v[2][i]);
		}
		else if (v[0][i] == v[2][i]) {
			res.push_back(v[1][i]);
		}
		else if (v[1][i] == v[2][i]) {
			res.push_back(v[0][i]);
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}