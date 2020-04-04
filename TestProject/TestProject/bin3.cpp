#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	vector<int> v;
	cin >> n >> d;
	v.push_back(0);
	v.push_back(2);
	v.push_back(14);
	v.push_back(11);
	v.push_back(21);
	v.push_back(17);
	v.push_back(d);
	vector<int> v1;
	for (int i = 0; i < v.size() - 1; i++) {
		int tmp = abs(v[i] - v[i + 1]);
		v1.push_back(tmp);
	}
	sort(v1.begin(), v1.end());
	int low = 1;
	int high = d;
	int ans = 0;
	int idx = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < v1.size(); i++) {
			if (mid >= v1[i]) {
				cnt++;
			}
			else {
				idx = i;
				break;
			}
		}
		if (cnt > n) {
			high = mid - 1;
		}
		else {
			ans = max(ans, v1[idx]);
			low = mid + 1;
		}
	}
	return 0;

	
}