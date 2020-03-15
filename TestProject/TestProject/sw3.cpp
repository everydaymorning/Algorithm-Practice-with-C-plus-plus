#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
vector<int> v, tmp;
int arr[11] = { 6,2,5,5,4,5,6,3,7,6 };
long long MAX;
int n;
void dfs(int cnt, string sum) {
	//cout << "cnt: " << cnt << " sum : " << sum << '\n';
	if (cnt > n) return;
	if (cnt == n) {
		string s;
		for (int i = 0; i < sum.size(); i++) {
			if (sum[i] != '0') s += sum[i];
		}
		long long tmp = stoll(s);
		MAX = max(MAX, tmp);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) cnt += arr[v[i]];
		else if (v[i] == 1) cnt += arr[v[i]];
		else if (v[i] == 2) cnt += arr[v[i]];
		else if (v[i] == 3) cnt += arr[v[i]];
		else if (v[i] == 4) cnt += arr[v[i]];
		else if (v[i] == 5) cnt += arr[v[i]];
		else if (v[i] == 6) cnt += arr[v[i]];
		else if (v[i] == 7) cnt += arr[v[i]];
		else if (v[i] == 8) cnt += arr[v[i]];
		else if (v[i] == 9) cnt += arr[v[i]];
		string str = to_string(v[i]);
		dfs(cnt, sum += str);
		cnt -= arr[v[i]];
		sum.pop_back();
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	dfs(0, "");
	cout << MAX;
	return 0;
}