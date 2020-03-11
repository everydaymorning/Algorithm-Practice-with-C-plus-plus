#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	vector<int> citations;
	citations.push_back(3);
	citations.push_back(0);
	citations.push_back(6);
	citations.push_back(1);
	citations.push_back(5);
	int ans = 0;
	sort(citations.begin(), citations.end(), cmp);
	int idx = 0;
	while (idx < citations.size()) {
		if (idx >= citations[idx]) return idx;
		idx++;
	}
	cout << ans;
	return 0;
}