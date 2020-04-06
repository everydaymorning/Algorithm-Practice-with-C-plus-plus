#include <bits/stdc++.h>
using namespace std;
bool check[51];
vector<int> nums;
vector<int> v;
int ans;

bool isPrime(int n) {
	bool flag = true;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			flag = false;
			break;
		}
	}
	if (flag) return true;
	else return false;
}
void dfs(int idx, int cnt) {
	if (cnt == 3) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		if (isPrime(sum)) {
			ans++;
		}
		return;
	}

	for (int i = idx; i < nums.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		v.push_back(nums[i]);
		dfs(i, cnt + 1);
		v.pop_back();
		check[i] = false;
	}
}
int main() {
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(4);

	dfs(0, 0);
	cout << ans;
	return 0;
}