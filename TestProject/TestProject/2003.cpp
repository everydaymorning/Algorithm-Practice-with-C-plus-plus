#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = i; j < n; j++) {
			tmp += arr[j];
			if (tmp == m) {
				cnt++;
				break;
			}
			else if (tmp > m) {
				break;
			}
		}
	}

	cout << cnt;
	return 0;
}