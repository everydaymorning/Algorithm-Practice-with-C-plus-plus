#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool com(const pair<int, int> &a, const pair<int ,int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n = 0;
	int cnt = 0;
	cin >> n;
	pair<int, int> a[100001];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a+n, com);

	
	int curL = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].first >= curL) {
			curL = a[i].second;
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}