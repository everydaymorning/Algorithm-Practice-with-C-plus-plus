#include <iostream>
#include <vector>
using namespace std;
int n;
bool check[200001];
vector<int> v1, v2;
int res;
void dfs(int idx, int cnt, int sum1, int sum2) {
	if (cnt == 2) {
		if (sum1 > sum2) {
			res++;
		}
		return;
	}
	for (int i = idx; i < v1.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		sum1 += v1[i];
		sum2 += v2[i];
		dfs(i, cnt + 1, sum1, sum2);
		sum1 -= v1[i];
		sum2 -= v2[i];
		check[i] = false;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v1.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v2.push_back(a);
	}

	dfs(0, 0, 0, 0);
	cout << res;
	return 0;
}