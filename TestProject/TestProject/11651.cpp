#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> v1,pair<int, int> v2) {
	if (v1.second == v2.second) {
		return v1.first < v2.first;
	}
	else {
		return v1.second < v2.second;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		int a = v.at(i).first;
		int b = v.at(i).second;

		cout << a << " " << b << '\n';
	}
	

	return 0;

}