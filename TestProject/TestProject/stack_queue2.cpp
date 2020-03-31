#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	vector<int> ans;
	stack<pair<int, int>> s;
	for (int i = 1; i <= v.size(); i++) {
		int tmp = v[i - 1];
		while (!s.empty()) {
			if (s.top().second > tmp) {
				ans.push_back(s.top().first);
				break;
			}
			s.pop();
		}

		if (s.empty()) {
			ans.push_back(0);
		}

		s.push({ i,v[i-1] });
	}


	return 0;
}