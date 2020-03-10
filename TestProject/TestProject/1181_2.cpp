#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
bool cmp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}