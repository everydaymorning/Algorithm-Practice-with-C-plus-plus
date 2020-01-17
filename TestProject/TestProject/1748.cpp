#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string n;
	cin >> n;
	int len = n.size();
	if (len == 1) {
		cout << n;
		return 0;
	}
	long long sum = 0;
	for (int i = 1; i < len; i++) {
		int tmp = (int)i * (9 * pow(10, i - 1));
		sum += tmp;
	}
	int num = atoi(n.c_str());
	int r = num - pow(10, len - 1) + 1;
	sum += (r * len);
	cout << sum;
	
	return 0;
}