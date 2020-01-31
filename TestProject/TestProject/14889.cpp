#include <bits/stdc++.h>
using namespace std;
int arr[21][21];
int n;
vector<int> start, link;
int mn = 2147483637;
void dfs(int idx) {
	if (idx >= n) {
		if (start.size() == link.size()) {
			int startSum = 0;
			int linkSum = 0;
			for (int i = 0; i < start.size(); i++) {
				for (int j = i + 1; j < start.size(); j++) {
					startSum += arr[start[i]][start[j]] + arr[start[j]][start[i]];
				}
			}

			for (int i = 0; i < link.size(); i++) {
				for (int j = i + 1; j < link.size(); j++) {
					linkSum += arr[link[i]][link[j]] + arr[link[j]][link[i]];
				}
			}

			mn = min(mn, abs(startSum - linkSum));
		}
		return;
	}
	start.push_back(idx);
	dfs(idx + 1);
	start.pop_back();

	link.push_back(idx);
	dfs(idx + 1);
	link.pop_back();
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0);

	cout << mn;

	return 0;

}