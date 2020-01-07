#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int cnt = 0;

	vector<string> v1;
	vector<string> result;
	v1.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}

	sort(v1.begin(), v1.end());

	for (int j = 0; j < m; j++) {
		string str;
		cin >> str;

		if (binary_search(v1.begin(), v1.end(), str)) {
			result.push_back(str);
			cnt++;
		}
	}

	sort(result.begin(), result.end());
	

	cout << cnt << '\n';
	int v_size = result.size();
	for (int i = 0; i < v_size; i++) {
		cout << result.at(i) << '\n';
	}

	return 0;
}