#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stones, int k) {
	int ans = 2147483647;
	int low = 2147483647;
	int high = 1;
	for (int i = 0; i < stones.size(); i++) {
		low = min(low, stones[i]);
		high = max(high, stones[i]);
	}
	while (low <= high) {
		vector<int> tmp = stones;
		int mid = (low + high) / 2;
		for (int i = 0; i < tmp.size(); i++) {
			tmp[i] -= mid;
		}
		int num = 0;
		int t = 0;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] <= 0) {
				num++;
			}
			else {
				t = max(t, num);
				num = 0;
			}
		}
		t = max(t, num);
		if (t >= k) {
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int main() {
	int a = 3;
	vector<int> s = { 1,1,1,1,1,1,1 };
	int ans = solution(s, a);
	cout << ans;
	return 0;
}