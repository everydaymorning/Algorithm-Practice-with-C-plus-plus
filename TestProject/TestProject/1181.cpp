#include <bits/stdc++.h>
using namespace std;
bool cmp(string tmp1, string tmp2) {
	if (tmp1.size() == tmp2.size()) return tmp1 < tmp2;
	return tmp1.size() < tmp2.size();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	int v_size = v.size();
	for (int i = 0; i < v_size; i++) {
		cout << v.at(i) << '\n';
	}

	return 0;
}