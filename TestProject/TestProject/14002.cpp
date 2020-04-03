#include <bits/stdc++.h>
using namespace std;
vector<int> lis;
vector<pair<int, int>> ans;
int arr[1001];
stack<int> s;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int j = 0;
	lis.push_back(arr[0]);
	ans.push_back({ 0,arr[0] });

	for (int i = 1; i < n; i++) {
		
		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);

			ans.push_back({ ++j, arr[i] });
			
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[idx] = arr[i];

			ans.push_back({ idx, arr[i] });
		}
	}

	cout << lis.size() << '\n';

	int tmp = lis.size() - 1;

	for (int i = n - 1; i >= 0; i--) {
		if (ans[i].first == tmp) {
			s.push(ans[i].second);
			tmp--;
		}
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}