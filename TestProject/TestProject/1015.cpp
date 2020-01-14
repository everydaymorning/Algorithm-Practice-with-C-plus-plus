#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> v1, pair<int, int> v2) {
	if (v1.second != v2.second) {
		return v1.second < v2.second;
	}
	return v1.first < v2.first;
}

bool cmp2(pair<int, int> v1, pair<int, int> v2) {
	return v1.first < v2.first;
}

vector<pair<int, int>> v;
vector<pair<int, int>> vv;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(make_pair(i, t));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		vv.push_back(make_pair(v.at(i).first, i));
	}

	sort(vv.begin(), vv.end(), cmp2);

	for (int i = 0; i < n; i++) {
		cout << vv.at(i).second << " ";
	}
	
	return 0;
}