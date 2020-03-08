#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> diff;
int n;
int MIN = 2147483647;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < v.size() - 1; i++) {
		int tmp = v[i + 1] - v[i];
		diff.push_back(tmp);
	}

	for (int i = 0; i < diff.size() - 1; i++) {
		int tmp = gcd(diff[i], diff[i + 1]);
		MIN = min(MIN, tmp);
	}
	int cnt = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i + 1] - v[i] != MIN) {
			int tmp = (v[i + 1] - v[i]) / MIN - 1;
			cnt += tmp;
		}
	}

	cout << cnt;
	return 0;
}