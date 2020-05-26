#include <bits/stdc++.h>
using namespace std;
int arr[6] = { 500, 100, 50, 10 ,5, 1 };
int main() {
	int n;
	cin >> n;
	int won = 1000 - n;

	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (won <= 0) break;
		if (arr[i] > won) continue;

		cnt += won / arr[i];
		won %= arr[i];
	}
	cout << cnt;
	return 0;
}