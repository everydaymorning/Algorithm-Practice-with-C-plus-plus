#include <bits/stdc++.h>
using namespace std;
int n;
string num;
void dfs(int idx, char tmp) {
	if (idx - 1 == n) {
		cout << num;
		exit(0);
	}
	num += tmp;
	//cout << "num: " << num << "  idx: " << idx << '\n';
	int r = idx / 2;
	for (int i = 1; i <= r; i++) {
		string a = num.substr(idx - i, i);
		string b = num.substr(idx - 2 * i, i);
		//cout << "a: " << a << "  b: " << b << '\n';
		if (a == b) {
			return;
		}
	}

	for (int i = 1; i <= 3; i++) {
		dfs(idx + 1, i + '0');
		num.pop_back();
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	dfs(1, '1');
	return 0;
}