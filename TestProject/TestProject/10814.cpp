#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, pair<int, int>> v1 , pair<string, pair<int, int>> v2) {
	if (v1.second.first == v2.second.first) {
		return v1.second.second < v2.second.second;
	}
	return v1.second.first < v2.second.first;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	vector<pair<string, pair<int, int>>> v;
	for (int i = 0; i < n; i++) {
		int t;
		string str;
		cin >> t >> str;
		v.push_back(make_pair(str, make_pair(t, i)));

	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v.at(i).second.first << " " << v.at(i).first << '\n';
	}

	return 0;
}