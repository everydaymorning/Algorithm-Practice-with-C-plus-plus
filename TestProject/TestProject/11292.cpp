#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<double, string> p1, pair<double, string> p2) {
	return p1.first > p2.first;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (1) {
		int t;
		cin >> t;
		if (t == 0) break;
		vector<pair<double, string>> v;
		for (int i = 0; i < t; i++) {
			string name;
			double num;
			cin >> name >> num;
			v.push_back({ num, name });
		}
		sort(v.begin(), v.end(), cmp);
		double tmp = v[0].first;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first == tmp) cout << v[i].second << " ";
		}
		cout << '\n';
	}
	return 0;
}